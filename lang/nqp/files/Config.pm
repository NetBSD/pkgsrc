use v5.10.1;

package NQP::Config::_Scoping;

sub new {
    my $class  = shift;
    my $cb     = shift;
    my %params = @_;
    my $self   = bless {}, $class;
    $self->{cb}     = $cb;
    $self->{params} = \%params;
    return $self;
}

sub DESTROY {
    my $self = shift;
    $self->{cb}->( %{ $self->{params} } );
}

package NQP::Config;
use strict;
use warnings;
use File::Spec;
use File::Spec::Unix;
use File::Basename;
use FindBin;
use Data::Dumper;
use NQP::Macros;
use IPC::Cmd qw<can_run run run_forked>;
use Cwd;
use Carp;
use ExtUtils::Command;

$SIG{__DIE__} = sub { confess @_ };

use base qw<Exporter>;
our @EXPORT    = qw<rm_l>;
our @EXPORT_OK = qw<
  os2platform slash slurp system_or_die run_or_die cmp_rev read_config read_config_from_command
>;

# Platform names will be incorporated into a regexp.
# unix will be used as the last resort option and thus will always be tested
# last.
my %os_platforms = (
    'windows' => [qw<MSWin32 os2>],
    'vms'     => [qw<VMS>],
    'unix'    => [qw<.*>],
);

my %platform_vars = (
    bat => {
        windows => '.bat',
        default => '',
    },
    exe => {
        windows => '.exe',
        default => '',
    },
    cpsep => {
        windows => ';',
        default => ':',
    },
    tab => {
        default => "\t",
    },
    env_open => {
        windows => '%',
        vms     => '%%',
        unix    => '$',
    },
    env_close => {
        windows => '%',
        vms     => '%%',
        unix    => '',
    },
    quote => {
        windows => q<">,
        default => q<'>,
    },
    shebang => {
        windows => qq<\n>,
        default => qq<#!/bin/sh\n>,
    },
    sh_allparams => {    # All command line params
        windows => q<%*>,
        default => q<$@>,
    },
);

sub new {
    my $self  = shift;
    my $class = ref($self) || $self;

    if ( $class eq __PACKAGE__ ) {
        die "Can't create instance of class " . $class
          . ", use a language sub-class instead";
    }

    my $new_obj = bless { config => {}, }, $class;
    $new_obj->init(@_);
    return $new_obj;
}

sub init {
    my $self   = shift;
    my %params = @_;

    my $config = $self->{config};

    $self->{quiet} = 0;

    $self->configure_platform;

    my $lang = $params{lang} // ( split /::/, ref($self) )[-1];

    $config->{perl}   = $^X;
    $config->{slash}  = slash();
    $config->{shell}  = $^O eq 'solaris' ? '' : "SHELL = " . $self->shell_cmd;
    $config->{lang}   = $lang;
    $config->{lclang} = lc $lang;

    # Num of spaces to indent lists in the Makefile
    $config->{list_indent} =
    $config->{filelist_indent} = 4;

    $self->{backend_prefix} = {
        moar => 'm',
        jvm  => 'j',
        js   => 'js',
    };

    # Precompiled files extensions
    $self->{backend_ext} = {
        moar => 'moarvm',
        jvm  => 'jar',
        js   => 'js',
    };

    # Value of nqp --target
    $self->{backend_target} = {
        moar => 'mbc',
        jvm  => 'jar',
        js   => 'js',
    };
    $self->{backends_order} = [qw<moar jvm js>];
    $self->{options}        = {
        'silent-build' => 1,
        'clean'        => 1,
    };
    $self->{contexts}  = [];
    $self->{repo_maps} = {
        rakudo => [qw<rakudo rakudo>],
        nqp    => [qw<Raku nqp>],
        moar   => [qw<MoarVM MoarVM>],
        roast  => [qw<Raku roast>],
    };

    $self->{impls} = {};
    for my $be ( @{ $self->{backends_order} } ) {
        $self->backend_config( $be, {} );
    }

    return $self;
}

sub msg {
    my $self = shift;
    return if $self->{quiet};
    print @_;
}

sub mute {
    my $self = shift;
    $self->{quiet} = @_ ? !!shift : 1;
}

sub _gen_msg {
    my $self = shift;
    my $type = shift;
    my @msg  = (
        "===$type===\n",
        join( "\n", map { "  $_" } split /\n/s, join( "", @_ ) )
    );
    return wantarray ? @msg : join( "", @msg );
}

sub sorry {
    my $self    = shift;
    my (@msg)   = @_;
    my $message = $self->_gen_msg( 'SORRY!', join( "\n", @msg ), "\n" );
    die $message unless $self->option('ignore-errors');
    print $message;
}

# Output a note-kind of message:
# ===TYPE===\n
#   Text
sub note {
    my $self = shift;
    say $self->_gen_msg(@_);
}

sub shell_cmd {
    $_[0]->is_win ? 'cmd' : 'sh';
}

sub batch_file {
    my $self   = shift;
    my $source = shift;
    my ( $vol, $dir, $file ) = File::Spec->splitpath($source);
    my $basename = basename( $file, "." . $self->cfg('bat') );
    return File::Spec->catpath( $vol, $dir, "$basename" . $self->cfg('bat') );
}

sub make_cmd {
    my $self = shift;

    my $config = $self->{config};

    my $make = 'make';
    if ( $self->is_solaris ) {
        $make = can_run('gmake');
        unless ($make) {
            die
"gmake is required to compile rakudo. Please install by 'pkg install gnu-make'";
        }
        $make = 'gmake';
    }

    if ( $self->is_bsd ) {
        $make = can_run('gmake');
        unless ($make) {

            # TODO Make sure it is BSD make by trying BSDmakefile
            $make = 'make';
        }
    }

    if ( $self->is_win ) {
        my $prefix    = $config->{prefix};
        my $has_nmake = 0 == system('nmake /? >NUL 2>&1');
        my $cl_report;
        my $has_cl = can_run('cl')
          && ( $cl_report = `cl 2>&1` ) =~ /Microsoft Corporation/;
        my $has_gmake = 0 == system('gmake --version >NUL 2>&1');
        my $has_gcc   = 0 == system('gcc --version >NUL 2>&1');
        if ($has_cl) {
            if ( $cl_report =~
                /Microsoft\s.*\sCompiler\s+Version\s+(\d+(?:\.\d+)+)/i )
            {
                my $actual_version = $1;
                my $expect_version = "19.0";
                if ( version->parse($actual_version) < $expect_version ) {
                    $self->sorry( "Expected Microsoft Compiler version "
                          . $expect_version
                          . "+, but got "
                          . $actual_version );
                }
            }
        }
        if (
            -x "$prefix\\bin\\nqp-m.exe"
            && ( $_ =
`"$prefix\\bin\\nqp-m.exe" -e "print(nqp::backendconfig()<make>)"`
            )
          )
        {
            $make = $_;
        }
        elsif (
            -x "$prefix\\bin\\nqp-m.bat"
            && ( $_ =
`"$prefix\\bin\\nqp-m.bat" -e "print(nqp::backendconfig()<make>)"`
            )
          )
        {
            $make = $_;
        }
        elsif ( $has_nmake && $has_cl ) {
            $make = 'nmake';
        }
        elsif ( $has_gmake && $has_gcc ) {
            $make = 'gmake';
        }
    }
    return $make;
}

sub options {
    $_[0]->{options};
}

sub option {
    die "Option name required for option method" unless @_ > 1;
    $_[0]->{options}{ $_[1] };
}

*opt = *option;

sub has_option {
    die "Option name required for has_option method" unless @_ > 1;
    exists $_[0]->{options}{ $_[1] };
}

sub validate_backend {
    my ( $self, $backend, $method ) = @_;
    $self->sorry( "Unknown backend '$backend'"
          . ( $method ? " in a call to method '$method'" : "" ) )
      unless $self->known_backend($backend);
    return $backend;
}

sub known_backends {
    my $self = shift;
    return @{ $self->{backends_order} };
}

sub known_backend {
    return exists $_[0]->{backend_prefix}{ $_[1] };
}

sub abbr_to_backend {
    my ( $self, $abbr ) = @_;
    unless ( $self->{abbr_to_backend} ) {
        for my $backend ( $self->known_backends ) {
            $self->{abbr_to_backend}{ $self->{backend_prefix}{$backend} } =
              $backend;
        }
    }
    die "Unknown backend abbreviation '$abbr' in call to abbr_to_backend"
      unless $self->{abbr_to_backend}{$abbr};
    return $self->{abbr_to_backend}{$abbr};
}

sub backend_abbr {
    my ( $self, $backend ) = @_;
    return $self->{backend_prefix}{ $self->validate_backend($backend) };
}

sub backend_ext {
    my ( $self, $backend ) = @_;
    return $self->{backend_ext}{ $self->validate_backend($backend) };
}

sub backend_target {
    my ( $self, $backend ) = @_;
    return $self->{backend_target}{ $self->validate_backend($backend) };
}

sub backend_config {
    my ( $self, $backend ) = ( shift, shift );
    if (@_) {
        my %config;
        if ( @_ == 1 && ref( $_[0] ) eq 'HASH' ) {
            %config = %{ $_[0] };
        }
        elsif ( @_ % 2 == 0 ) {
            %config = @_;
        }
        else {
            die "Bad configuration hash passed in to backend_config";
        }
        @{ $self->{impls}{$backend}{config} }{ keys %config } =
          values %config;
    }
    return $self->{impls}{$backend}{config};
}

sub known_abbrs {
    return values %{ $_[0]->{backend_prefix} };
}

sub use_backend {
    my ( $self, $backend ) = @_;
    return if $self->active_backend($backend);
    push @{ $self->{active_backends_order} }, $backend;
    $self->{active_backends}{ $self->validate_backend($backend) } = 1;
    $self->{config}{default_backend} ||= $backend;
    $self->{config}{default_prefix}  ||= $self->backend_abbr($backend);
}

sub active_backends {
    my $self = shift;
    return () unless $self->{active_backends_order};
    return @{ $self->{active_backends_order} };
}

sub active_backend {
    my ( $self, $backend ) = @_;
    return !!$self->{active_backends}{ $self->validate_backend($backend) };
}

sub active_abbrs {
    my $self = shift;
    return map { $self->backend_abbr($_) } $self->active_backends;
}

# Takes a relative path
sub base_path {
    my $self     = shift;
    my @rel_path = @_;

    if ( @rel_path == 1 ) {
        return $rel_path[0]
          if File::Spec->file_name_is_absolute( $rel_path[0] );
        @rel_path = File::Spec->splitdir( $rel_path[0] );
    }

    return File::Spec->catfile( $self->{config}{base_dir}, @rel_path );
}

# This one is called by init
sub configure_platform {
    my $self   = shift;
    my $config = $self->{config};

    $config->{OS} //= $^O;
    $config->{platform} = os2platform( $config->{OS} );

    for my $var ( keys %platform_vars ) {
        my $val =
          $platform_vars{$var}{ $config->{platform} }
          // $platform_vars{$var}{default} // die(
            "Config variable '$var' is not defined for $config->{platform}");
        $config->{$var} = $val;
    }
}

sub configure_paths {
    my $self   = shift;
    my $config = $self->{config};

    my $base_dir = $self->nfp($FindBin::Bin);

    $config->{base_dir}  = $base_dir;
    $config->{build_dir} = File::Spec->catdir( $base_dir, 'tools', 'build' );
    $config->{templates_dir} =
      File::Spec->catdir( $base_dir, 'tools', 'templates' );
    $config->{configure_script} = File::Spec->canonpath(
        File::Spec->catfile( $base_dir, $FindBin::Script ) );
}

sub configure_jars {
    my $self = shift;
    my $jars = shift;

    my $config  = $self->{config};
    my $options = $self->{options};

    foreach my $name ( keys %$jars ) {
        my $path     = $jars->{$name};
        my $variable = $name;
        $variable =~ s/-//;
        if ( $options->{"with-$name"} ) {
            if ( $options->{"with-$name"} ne '-' ) {
                $config->{$variable} = $options->{"with-$name"};
            }
        }
        else {
            $config->{$variable} = $self->base_path( @{$path} );
        }

        $config->{ $variable . 'file' } =
          ( File::Spec->splitpath( $config->{$variable} ) )[-1];
    }
}

sub configure_relocatability {
    my $self = shift;

    # Relocatability is not supported on AIX and OpenBSD.
    if ( $^O =~ /^(?:aix|openbsd)$/ && $self->{options}->{relocatable} ) {
        $self->sorry( 'Relocatability is not supported on '
              . $^O
              . ".\nLeave off the --relocatable flag to do a non-relocatable build."
        );
    }

    if (
        $self->{options}->{relocatable}
        && (   $self->{options}->{'rakudo-home'}
            || $self->{options}->{'nqp-home'} )
      )
    {
        $self->sorry(
"It's not possible to build a relocatable rakudo and use hard coded rakudo-home"
              . "\nor nqp-home directories. So either don't use the `--relocatable` parameter or don't"
              . "\nuse the `--perl6-home`, `--rakudo-home`, and `--nqp-home` parameters."
        );
    }

    $self->{config}->{relocatable} =
      $self->{options}->{relocatable} ? 'reloc' : 'nonreloc';
}

# This would prepare git URL config variables for default protocol.
sub configure_repo_urls {
    my $self = shift;

    # Pre-cache repo urls to make them available for makefiles.
    for my $r ( keys %{ $self->{repo_maps} } ) {
        $self->repo_url( $r, action => 'pull' );
        $self->repo_url( $r, action => 'push' );
    }
}

sub configure_commands {
    my $self   = shift;
    my $config = $self->{config};

    $config->{make} = $self->make_cmd;

    my $buf;
    for (my $retries = 50; $retries; $retries--) {
        my $ok = run( command => [ $config->{make}, q<-v> ], buffer => \$buf );
        unless ($ok) {
            $ok = run( command => [ $config->{make}, q</?> ], buffer => \$buf );
        }
        if ( $buf =~ /^GNU Make/s ) {
            $config->{make_family}       = 'gnu';
            $config->{make_first_prereq} = '$<';
            $config->{make_all_prereq}   = '$^';
            $config->{make_pp_pfx} = '';    # make preprocessor directive prefix
        }
        elsif ( $buf =~ /Microsoft/s ) {
            $config->{make_family}       = 'nmake';
            $config->{make_first_prereq} = '%s';
            $config->{make_all_prereq}   = '$**';
            $config->{make_pp_pfx}       = '!';
        }
        elsif ( $self->is_bsd && $config->{make} =~ /\bmake$/ ) {
            $config->{make_family}       = 'bsd';
            $config->{make_first_prereq} = '${>:[1]}';
            $config->{make_all_prereq}   = '$>';
            $config->{make_pp_pfx}       = '.';
        }
        last if defined $config->{make_family};
    }
    unless ( defined $config->{make_family} ) {
        $self->sorry(
                "Cannot determine the brand of your $config->{make} utility."
              . "\nIt is reporting itself as:\n"
              . $buf );
    }

    if ( $self->isa_unix ) {
        $config->{mkpath} = 'mkdir -p --';
        $config->{chmod}  = 'chmod --';
        $config->{cp}     = 'cp --';

        # Symlinking should override destination.
        $config->{ln_s}   = $self->is_aix
                            ? '$(PERL5) ' 
                                . $self->shell_quote_filename(
                                    File::Spec->catfile(
                                        $self->cfg('base_dir'),
                                        'tools', 'build', 'ln_s.pl'))
                            : 'ln -nfs --';
        $config->{rm_f}   = 'rm -f --';
        $config->{rm_rf}  = 'rm -rf --';
        $config->{rm_l}   = 'rm -f --';
        $config->{test_f} = 'test -f --';
    }
    else {
        $config->{mkpath} = '$(PERL5) -MExtUtils::Command -e mkpath';
        $config->{chmod}  = '$(PERL5) -MExtUtils::Command -e chmod';
        $config->{cp}     = '$(PERL5) -MExtUtils::Command -e cp';
        $config->{ln_s}   = '$(PERL5) -MExtUtils::Command -e cp';
        $config->{rm_f}   = '$(PERL5) -MExtUtils::Command -e rm_f';
        $config->{rm_rf}  = '$(PERL5) -MExtUtils::Command -e rm_rf';
        $config->{rm_l} =
            '$(PERL5) -I'
          . $self->nfp( $self->cfg('base_dir') . '/3rdparty/nqp-configure/lib' )
          . ' -MNQP::Config -e rm_l';
        $config->{test_f} = '$(PERL5) -MExtUtils::Command -e test_f';
        $config->{test_f} = '$(PERL5) -MExtUtils::Command -e test_f';
    }
}

sub abstract {
    my @c = caller(1);
    die "Method $c[3] must be implemented by the language class";
}

sub configure_backends {
    abstract;
}

sub configure_misc {
    my $self        = shift;
    my $config      = $self->{config};
    my $make_pp_pfx = $self->cfg('make_pp_pfx');
    if ( $self->cfg('silent_build') eq 'on' ) {
        $config->{NOECHO_declaration} = <<NOECHO_DECL;
NOECHO = @
${make_pp_pfx}ifdef VERBOSE_BUILD
NOECHO =
${make_pp_pfx}endif
NOECHO_DECL
    }
    else {
        $config->{NOECHO_declaration} = <<NOECHO_DECL;
NOECHO =
${make_pp_pfx}ifdef SILENT_BUILD
NOECHO = @
${make_pp_pfx}endif
NOECHO_DECL
    }
}

sub configure_refine_vars {
    my $self   = shift;
    my $config = $self->{config};

    $self->{config}{runner_suffix} = $self->{config}{bat};

    unless ( $config->{prefix} ) {

        # XXX This is only Unix-friendly way.
        my $default =
          defined( $self->option('sysroot') )
          ? ( $self->option('sysroot') || '/usr' )
          : File::Spec->catdir( $config->{base_dir}, 'install' );
        $self->note( "ATTENTION",
            "No --prefix supplied, building and installing to $default\n" );
        $config->{prefix} = $default;
    }
    $config->{prefix} = File::Spec->rel2abs( $config->{prefix} );
}

sub parse_backends {
    my $self            = shift;
    my $passed_backends = shift;
    return uc($passed_backends) eq 'ALL'
      ? $self->known_backends
      : map { lc } split /,\s*/, $passed_backends;
}

sub backend_error {
    my $self    = shift;
    my $backend = shift;
    $self->{backend_errors}{$backend} //= [];
    if (@_) {
        push @{ $self->{backend_errors}{$backend} }, @_;
    }
    return !!@{ $self->{backend_errors}{$backend} };
}

sub backend_errors {
    my $errs = $_[0]->{backend_errors}{ $_[1] };
    return wantarray ? @$errs : $errs;
}

sub configure_active_backends {
    my $self = shift;

    # Most likely this would never fire. But better stay on the safe side of the
    # Moon.
    $self->sorry("No active backends found. Please, use --backends option.")
      unless $self->active_backends;

    for my $b ( $self->active_backends ) {
        $self->{backend_errors}{$b} = [];
        my $method = "configure_${b}_backend";
        $self->$method();
    }

    $self->post_active_backends;
}

sub configure_from_options {
    my $self   = shift;
    my $config = $self->{config};
    for my $opt (
        qw<prefix rakudo-home nqp-home sdkroot sysroot github-user git-protocol
        rakudo-repo nqp-repo moar-repo roast-repo makefile-timing
        relocatable git-cache-dir>
      )
    {
        ( my $ckey = $opt ) =~ s/-/_/g;
        $self->set_key( $ckey, $self->{options}{$opt}, default => '', );
    }

    for my $opt ( keys %{ $self->{options} } ) {
        my $opt_val = $self->{options}{$opt} // '';
        next if ref($opt_val);
        ( my $cf_var = $opt ) =~ s/-/_/g;
        $config->{"opt_$cf_var"} = $opt_val;
    }

    if ( $self->{options}{'git-reference'} ) {
        print "===WARNING!===\n";
        print "The --git-reference option does not exist anymore.\n";
        print "Consider using --git-cache-dir instead.\n";
    }

    $config->{stagestats} = '--stagestats'
      if $self->{options}{'makefile-timing'};

    $config->{silent_build} = $self->option('silent-build') ? "on" : "off";

    my ( $template, $out );
    if ( $self->option('expand') ) {
        $self->mute;
        $template             = $self->option('expand');
        $out                  = $self->option('out');
        $self->{expand_as_is} = 1;
    }
    else {
        $template = 'Makefile';
        $out      = File::Spec->catfile( $config->{base_dir}, 'Makefile' );
        $self->{out_header} = "\n# Makefile code generated by Configure.pl:\n";
        $self->{expand_as_is} = 0;
    }
    $self->{template} = $template;
    $self->{out}      = $out if $out && ( $out ne '-' );

    for ( @{ $self->option('set-var') // [] } ) {
        if (/^(\w+)=(.*)$/) {
            $config->{$1} = $2;
        }
        else {
            die "Bad set config variable string: '$_'";
        }
    }
}

sub expand_template {
    my $self = shift;

    my $outh;
    eval {

        if ( $self->{out} ) {
            open $outh, '>', $self->{out}
              or die "Cannot open '$self->{out}' for writing: $!";
        }
        else {
            $outh = \*STDOUT;
        }

        print $outh $self->{out_header} if $self->{out_header};

        $self->fill_template_file(
            $self->template_file_path( $self->{template}, required => 1 ),
            $outh, as_is => $self->{expand_as_is} );

        if ( $self->{out} ) {
            close $outh
              or die "Error while writing to '$self->{out}': $!";
        }
    };
    if ($@) {
        close $outh if $outh;
        unlink $self->{out};
        die $@;
    }
}

sub save_config_status {
    my $self   = shift;
    my $config = $self->{config};

    # Save options in config.status
    my $status_file = $self->base_path('config.status');
    unlink($status_file);
    if ( open( my $CONFIG_STATUS, '>', $status_file ) ) {
        my $ckey = $config->{lclang} . "_config_status";
        print $CONFIG_STATUS "$^X Configure.pl $config->{$ckey} \$*\n";
        close($CONFIG_STATUS);
    }
    else {
        warn "Can't write to $status_file: $!";
    }
}

sub make_option {
    my $self   = shift;
    my $opt    = shift;
    my %params = @_;

    my $options = $self->{options};

    state $bool_opt = {
        map { $_ => 1 }
          qw<
          force-rebuild relocatable no-clean ignore-errors silent-build
          >
    };

    my $opt_str = "";
    if ( $bool_opt->{$opt} ) {
        $opt_str = "--" . ( $options->{$opt} ? '' : 'no-' ) . "$opt";
    }
    elsif ( defined $options->{$opt} ) {
        my $opt_value =
          ref( $options->{$opt} )
          ? join( ",", @{ $options->{$opt} } )
          : $options->{$opt};
        if ( $params{no_quote} ) {
            $opt_str = qq{--$opt=$opt_value};
        }
        else {
            $opt_str = qq{--$opt=} . $self->shell_quote_filename($opt_value);
        }
    }
    return $opt_str;
}

# Can be overriden by lang-specific module to modify the list.
sub ignorable_opts {
    my $self = shift;
    my $opt  = shift;
    return qw<gen-moar gen-nqp force-rebuild help make-install expand out
      prefix backends set-var silent-build clean>;
}

# Generate Configure.pl options from the data we have so far.
sub opts_for_configure {
    my $self = shift;
    my @opts = @_;
    my @subopts;

    @opts = keys %{ $self->{options} } unless @opts;

    my @ignorables   = $self->ignorable_opts;
    my $ignorable_re = '^(?:' . join( '|', map { "$_" } @ignorables ) . ')$';

    for my $opt ( grep { !/$ignorable_re/ } @opts ) {
        my $opt_str = $self->make_option($opt);
        push @subopts, $opt_str if $opt_str;
    }
    push @subopts, "--backends=" . join( ",", $self->active_backends );
    push @subopts,
      "--prefix=" . $self->shell_quote_filename( $self->cfg('prefix') );
    push @subopts, "--silent-build" if $self->option('silent-build');
    return wantarray ? @subopts : join( " ", @subopts );
}

sub is_win {
    state $win = $^O eq 'MSWin32';
    return $win;
}

sub is_solaris {
    state $solaris = $^O eq 'solaris';
    return $solaris;
}

sub is_bsd {
    state $bsd = $^O =~ /bsd|dragonfly/;
    return $bsd;
}

sub is_aix {
    state $aix = $^O =~ /aix/;
    return $aix;
}

sub isa_unix {

    # The following is a partial OS list taken from Perl::OSType module,
    # copyright by David Golden. The up-to-date version of that module can
    # be found at https://metacpan.org/pod/Perl::OSType

    return 1 if grep $^O eq $_, qw/
      aix       bsdos        beos   bitrig  dgux      dragonfly  dynixptx
      freebsd   linux        haiku  hpux    iphoneos  irix       darwin
      machten   midnightbsd  minix  mirbsd  next      openbsd    netbsd
      dec_osf   nto          svr4   svr5    sco       sco_sv     unicos
      unicosmk  solaris      sunos  cygwin  msys      os2        interix
      gnu       gnukfreebsd  nto    qnx     android
      /;

    return 0;
}

sub is_executable {
    my ( $self, $file ) = @_;
    die "File parameter is missing in call to is_executable" if @_ < 2;
    return $file                                             if -x $file;
    for my $ext (qw<exe bat>) {
        my $fname = $file . $self->cfg($ext);
        return $fname if -x $fname;
    }
    return 0;
}

sub github_url {
    my $self = shift;
    my ( $protocol, $user, $repo ) = @_;
    $protocol = lc( $protocol // 'https' );
    if ( $protocol eq 'https' || $protocol eq 'git' ) {
        return sprintf '%s://github.com/%s/%s.git', $protocol, $user, $repo;
    }
    elsif ( $protocol eq 'ssh' ) {
        return sprintf 'git@github.com:%s/%s.git', $user, $repo;
    }
    else {
        die "Unknown protocol '$protocol' (fine are: ssh, https, git)";
    }
}

sub repo_url {
    my $self     = shift;
    my $repo     = shift;
    my %params   = @_;
    my $action   = $params{action} || 'pull';
    my $protocol = $params{protocol};
    my $config   = $self->{config};

    die "Unknown repository type '$repo'" unless $self->{repo_maps}{$repo};
    die "Bad action type '$action'" unless $action =~ /^(push|pull)$/;

    my $gproto =
      $action eq 'push'
      ? 'ssh'
      : $protocol || $config->{git_protocol} || 'https';
    my $ckey     = "${repo}_${action}_url";
    my $repo_key = $repo . "_repo";

    # Return user defined repo if there is one
    if ( $config->{$repo_key} ) {
        return $config->{$ckey} = $config->{$repo_key};
    }

    # Return cached response.
    return $config->{$ckey} if $config->{$ckey} && !$protocol;

    my ( $guser, $grepo ) = @{ $self->{repo_maps}{$repo} };
    $guser = $config->{github_user} if $config->{github_user};
    my $url = $self->github_url( $gproto, $guser, $grepo );
    $config->{$ckey} = $url unless $protocol;
    return $url;
}

sub include_path {
    my $self = shift;

    my @incs;
    for my $ctx ( $self->contexts ) {
        next unless $ctx->{including_file};
        if (@incs) {
            push @incs, "\tincluded from $ctx->{including_file}";
        }
        else {
            push @incs, " in file $ctx->{including_file}";
        }
    }
    return join( "\n", @incs );
}

sub find_filepath {
    my $self   = shift;
    my $src    = shift;
    my %params = @_;
    my $config = $self->config;

    return $src if File::Spec->file_name_is_absolute($src);

    my @subdirs;

    push @subdirs, $params{subdir}       if $params{subdir};
    push @subdirs, @{ $params{subdirs} } if $params{subdirs};
    push @subdirs, "" unless $params{subdirs_only};

    my $ctx_subdir = $self->cfg('ctx_subdir');
    push @subdirs, $ctx_subdir if $ctx_subdir;

    my $where     = $params{where} || 'templates';
    my $where_dir = $self->cfg( "${where}_dir", strict => 1 );
    my @suffixes;
    push @suffixes, $params{suffix}        if $params{suffix};
    push @suffixes, @{ $params{suffixes} } if $params{suffixes};

    for my $subdir (@subdirs) {
        my $try_dir = File::Spec->catdir( $where_dir, $subdir );
        for my $sfx (@suffixes) {

            # Don't append extension if it's already there.
            next if $sfx && $src =~ /\Q$sfx\E$/;
            my $tfile = File::Spec->catfile( $try_dir, $src . $sfx );
            return $tfile if -e $tfile;
        }
    }
    die "File '$src' not found in base directory $where_dir"
      . $self->include_path
      if $params{required};
    return "";
}

sub template_file_path {
    my $self = shift;
    return $self->find_filepath(
        shift,
        suffixes => [ "." . $self->cfg('platform'), ".in", "" ],
        @_
    );
}

sub build_file_path {
    my $self = shift;
    return $self->find_filepath(
        shift,
        where    => 'build',
        suffixes => [ qw<.pl .nqp .p6>, "" ],
        @_
    );
}

sub fill_template_file {
    my $self = shift;
    my ( $infile, $outfile ) = @_;
    my %params = @_;

    my $OUT;
    if ( ref $outfile ) {
        $OUT = $outfile;
    }
    else {
        $self->msg("\nCreating $outfile ...\n");
        open( $OUT, '>', $outfile )
          or die "Unable to write $outfile\n";
    }

    my @infiles = ref($infile) ? @$infile : $infile;
    for my $if (@infiles) {
        my $ifpath = $self->template_file_path( $if, required => 1, );
        my $s      = $self->push_ctx(
            {
                template_file => $ifpath,
                configs       => [
                    {
                        template_file => $ifpath,
                    }
                ],
            }
        );
        my $text = slurp($ifpath);
        print $OUT "\n# Generated from $ifpath\n" unless $params{as_is};
        $text = $self->fill_template_text( $text, source => $ifpath );
        print $OUT $text;
        print $OUT "\n\n# (end of section generated from $ifpath)\n\n"
          unless $params{as_is};
    }
}

sub fixup_makefile {
    my $self = shift;
    my $text = shift;

    #if ( $self->is_win ) {
    #    $text =~ s{/}{\\}g;
    #    $text =~ s{\\\*}{\\\\*}g;
    #    $text =~ s{(?:git|http):\S+}{ do {my $t = $&; $t =~ s'\\'/'g; $t} }eg;
    #    $text =~ s/.*curl.*/do {my $t = $&; $t =~ s'%'%%'g; $t}/meg;
    #}

    # TODO Timing is better be implemented as a macro
    if ( $self->cfg('makefile_timing') ) {
        $text =~ s{ (?<!\\\n)        # not after line ending in '\'
                        ^                # beginning of line
                        (\t(?>@?[ \t]*)) # capture tab, optional @, and hspace
                        (?!-)            # not before - (ignore error) lines
                        (?!cd)           # not before cd lines
                        (?!echo)         # not before echo lines
                        (?=\S)           # must be before non-blank
                      }
                      {$1time\ }mgx;
    }
    return $text;
}

sub fill_template_text {
    my $self   = shift;
    my $text   = shift;
    my %params = @_;
    my $config = $self->config;

    my $on_fail = sub {
        my $err = shift;
        my $msg = ref($err)
          && $err->isa('NQP::Macros::_Err') ? $err->message : $err;
        my $src = $params{source} ? " in template $params{source}" : "";
        $self->sorry("$msg$src");
    };

    my $text_out =
      NQP::Macros->new( config => $self, on_fail => $on_fail )->expand($text);

    # XXX This is better be handled with makefile macros. Then the whole method
    # would be easily replaced with Macros->expand()
    if ( $text_out =~ /nqp::makefile/ ) {
        $text_out = $self->fixup_makefile($text_out);
    }
    $text_out;
}

sub reference_dir {
    my ($self, $name) = @_;
    my $git_cache_dir = $self->cfg('git_cache_dir');
    return File::Spec->catdir( $git_cache_dir, $name );
}

sub git_checkout {
    my ( $self, $repo, $dir, $checkout ) = @_;

    die "Unknown repository '$repo' in call to git_checkout"
      unless $self->{repo_maps}{$repo};

    my $config  = $self->config;
    my $options = $self->{options};
    my $pwd     = cwd();
    my $pullurl = $self->repo_url( $repo, action => 'pull' );
    my $pushurl = $self->repo_url( $repo, action => 'push' );

    # Clone / fetch git reference repo
    if ( $config->{git_cache_dir} ) {
        my $ref_dir =
          $self->reference_dir( $self->{repo_maps}{$repo}[1] );
        if ( !-d $ref_dir ) {
            my @ref_args = ( 'git', 'clone', '--bare' );
            push @ref_args, "--depth=$options->{'git-depth'}"
              if $options->{'git-depth'};
            push @ref_args, $pullurl, $ref_dir;
            $self->msg("Cloning reference from $pullurl\n");
            system_or_die(@ref_args);
        }
        else {
            chdir($ref_dir);
            system_or_die( 'git', 'fetch' );
            chdir($pwd);
        }
    }
    # get an up-to-date repository
    if ( !-d $dir ) {
        my @args = ( 'git', 'clone' );
        if ( $config->{git_cache_dir} ) {
            my $ref_dir =
              $self->reference_dir( $self->{repo_maps}{$repo}[1] );
            die "Can't find $repo reference directory in $config->{git_cache_dir}"
              unless $ref_dir;
            push @args, "--reference=$ref_dir";
        }
        push @args, "--depth=$options->{'git-depth'}"
          if $options->{'git-depth'};
        push @args, $pullurl, $dir;
        $self->msg("Cloning from $pullurl\n");
        system_or_die(@args);
        chdir($dir);

        system( 'git', 'config', 'remote.origin.pushurl', $pushurl )
          if defined $pushurl && $pushurl ne $pullurl;
    }
    else {
        chdir($dir);
        system_or_die( 'git', 'fetch' );

        # pre-git 1.9/2.0 `--tags` did not fetch tags in addition to normal
        # fetch https://stackoverflow.com/a/20608181/2410502 so do it separately
        system_or_die( 'git', 'fetch', '--tags' );
    }

    if ($checkout) {
        system_or_die( 'git', 'checkout', $checkout );
        system_or_die( 'git', 'pull' )
          if slurp('.git/HEAD') =~ /^ref:/;
    }

    my $git_describe;
    if ( open( my $GIT, '-|', "git describe --tags" ) ) {
        $git_describe = <$GIT>;
        close($GIT);
        chomp $git_describe;
    }
    chdir($pwd);
    $git_describe;
}

sub _restore_ctx {
    my %params = @_;
    my $obj    = $params{obj};

    my $idx = 0;

    for my $ctx ( @{ $obj->{contexts} } ) {
        if ( $ctx == $params{ctx} ) {
            splice( @{ $obj->{contexts} }, $idx, 1 );
            return;
        }
        ++$idx;
    }
}

sub contexts {
    my @c = reverse @{ $_[0]->{contexts} };
}

sub cur_ctx {
    return {} unless @{ $_[0]->{contexts} };
    $_[0]->{contexts}[-1];
}

sub push_ctx {
    my $self = shift;
    my $ctx  = shift;

    die "Context must be a hash" unless ref($ctx) eq 'HASH';

    warn "Context has 'config' key. Didn't you mean 'configs'?"
      if exists $ctx->{config};

    my @c = caller(1);

    $ctx->{".ctx"} = {
        from => {
            file => $c[1],
            line => $c[2],
            sub  => $c[3],
        },
    };

    if ( $ctx->{configs} ) {
        if ( ref( $ctx->{configs} ) ) {
            my $is_valid = 1;
            if ( ref( $ctx->{configs} ) eq 'ARRAY' ) {
                for my $cfg ( @{ $ctx->{configs} } ) {
                    if ( ref($cfg) ne 'HASH' ) {
                        $is_valid = 0;
                        last;
                    }
                }
            }
            else {
                $is_valid = 0;
            }
            die "'configs' key of context must be a list of hashes"
              unless $is_valid;
        }
        else {
            $ctx->{configs} = [ $ctx->{configs} ];
        }
    }
    else {
        $ctx->{configs} = [];
    }

    push @{ $self->{contexts} }, $ctx;

    return NQP::Config::_Scoping->new(
        \&_restore_ctx,
        obj => $self,
        ctx => $ctx
    );
}

sub pop_ctx {
    my $self = shift;
    return pop @{ $self->{contexts} };
}

# Quick push of a single config hash to the context stack.
sub push_config {
    my $self = shift;
    my $ctx_config;

    if ( @_ == 1 ) {
        $ctx_config = shift;
    }
    else {
        my %c = @_;
        $ctx_config = \%c;
    }

    die "push_config is expecting a hash variable => value pairs, not a "
      . ( ref($ctx_config) || 'scalar' )
      unless ref($ctx_config) eq 'HASH';

    return $self->push_ctx( { configs => [$ctx_config], } );
}

sub set_key {
    my $self = shift;
    my ( $key, $val, %params ) = @_;
    $val //= $params{default};
    return $self->{config}{$key} = $val;
}

sub config {
    my $self   = shift;
    my %params = @_;

    return $self->{config} if $params{no_ctx};

    my %config = %{ $self->{config} };

    for my $ctx ( @{ $self->{contexts} } ) {

        # Reversing because the first must override the last.
        for my $ctx_cfg ( reverse @{ $ctx->{configs} } ) {
            @config{ keys %$ctx_cfg } = values %$ctx_cfg;
        }
    }

    return \%config;
}

# Searches for a config variable in contexts (from latest pushed upwards) and
# then in the main config. If context contains more than one config hash in
# configs key then they're searched forward, from the first to the last.
sub cfg {
    my $self   = shift;
    my $var    = shift;
    my %params = @_;

    # Don't use config method for better performance.
    for my $ctx ( $self->contexts ) {
        my $configs = $ctx->{configs};
        for my $config (@$configs) {
            if ( exists $config->{$var} ) {
                if ( $params{with_ctx} && wantarray ) {
                    return ( $config->{$var}, $ctx );
                }
                return $config->{$var};
            }
        }
    }

    die "Can't find configuration variable '$var'"
      if $params{strict} && !exists $self->{config}{$var};

    return $self->{config}{$var};
}

# Set a configuration variable. Note that by default the variable is set on the
# root config hash.
sub set {
    my $self   = shift;
    my $key    = shift;
    my $val    = shift;
    my %params = @_;

    if ( my $prop = $params{in_ctx} ) {
        my $ctx;
        if ( $prop eq -1 ) {
            $ctx = $self->{contexts}[-1];
        }
        else {
            unless ( $ctx = $self->in_ctx($prop) ) {
                $self->sorry( "No context '$prop' found"
                      . " while attemtped to set variable $key" );
            }
        }
        $ctx->{configs}[-1]{$key} = $val;
    }
    else {
        $self->{config}{$key} = $val;
    }

    return $self;
}

# Same as cfg but looking for a property, i.e. a key on a context or config
# object itself.
sub prop {
    my $self   = shift;
    my $name   = shift;
    my %params = @_;

    for my $ctx ( $self->contexts ) {
        return $ctx->{$name} if exists $ctx->{$name};
    }

    die "Can't find property '$name'"
      if $params{strict} && !exists $self->{$name};

    return $self->{$name};
}

# $config->in_ctx(prop_name => "prop value")
sub in_ctx {
    my $self = shift;
    my ( $prop, $val ) = @_;

    for my $ctx ( $self->contexts ) {
        return $ctx
          if exists $ctx->{$prop}
          && ( !defined($val) || ( $ctx->{$prop} eq $val ) );
    }

    return 0;
}

sub shell_quote_filename {
    my $self     = shift;
    my $filename = shift;

    my $platform = $self->cfg('platform');

    my $qchar = $self->cfg('quote');
    my $out   = $filename;

    if ( $platform eq 'windows' ) {
        $filename =~ s{(%)}{$1$1}g;
        $filename =~ s{(")}{\\$1}g;
    }
    elsif ( $platform eq 'unix' ) {
        $filename =~ s{'}{'\\''}g;
    }

    $out = "$qchar$filename$qchar";

    return $out;
}

sub nfp {
    my $self = shift;
    my ( $vol, $dirs, $file ) = File::Spec->splitpath(shift);
    my %params   = @_;
    my $filename = File::Spec->canonpath(
        File::Spec->catpath(
            $vol,
            File::Spec->catdir( File::Spec::Unix->splitdir($dirs) ), $file
        )
    );
    $filename = $self->shell_quote_filename($filename) if $params{quote};
    return $filename;
}

sub c_escape_string {
    my $self = shift;
    my $str  = shift;
    $str =~ s{\\}{\\\\}sg;
    $str =~ s{"}{\\"}sg;
    return $str;
}

sub sq_escape_string {
    my $self = shift;
    my $str  = shift;
    $str =~ s{\\}{\\\\}sg;
    $str =~ s{'}{\\'}sg;
    return $str;
}

#########################################################
### Non-method subs
#########################################################

sub slash {
    state $slash = File::Spec->catfile( '', '' );
    return $slash;
}

sub slurp {
    my $filename = shift;
    open my $fh, '<', $filename
      or die "Unable to read file '$filename'\n";
    local $/ = undef;
    my $text = <$fh>;
    close $fh or die $!;
    return $text;
}

sub os2platform {
    my $os = shift // $^O;

    # Make unix always be the last tried
    my @platforms =
      ( ( grep { $_ ne 'unix' } keys %os_platforms ), 'unix' );

    my $platform;
    for my $p (@platforms) {
        my $p_or = "(?:" . join( "|", @{ $os_platforms{$p} } ) . ")";
        if ( $os =~ /^$p_or$/ ) {
            $platform = $p;
            last;
        }
    }

    $platform;
}

# Command line support, similar to ExtUtils::Command
sub rm_l {
    ExtUtils::Command::expand_wildcards();
    for my $link (@ARGV) {
        my $rc;
        if ( $^O eq 'MSWin32' ) {
            $rc = rmdir $link;
        }
        else {
            unlink $link;
        }
        die "Can't delete directory $_: $!" unless $rc;
    }
}

sub system_or_die {
    my @cmd = @_;
    system(@cmd) == 0
      or die "Command failed (status $?): @cmd\n";
}

# qx{} replacement and process timing out protection.
sub run_or_die {
    my ( $cmd, %params ) = @_;
    my $buf;
	my $ok = 1;
	my $reason;
	my $cmdstr = ref($cmd) eq 'ARRAY' ? join( " ", @$cmd ) : $cmd;
	if ($params{output_timeout} && IPC::Cmd->can_use_run_forked) {
		my $last_out_at = time;
		my $output_timeout = delete $params{output_timeout};
		my $verbose = delete $params{verbose};
		my $heartbeat = delete $params{heartbeat};
		my $description = delete($params{description}) // '... Command `' . $cmdstr . '`';
		my $on_stdout = sub {
			print join("", @_) if $verbose;
			$last_out_at = time;
		};
		my $on_stderr = sub {
			print STDERR join("", @_) if $verbose;
			$last_out_at = time;
		};
		my $started = time;
		my $last_heartbeat = time;
		my $resp = run_forked $cmd, 
					{
						stdout_handler => $on_stdout, 
						stderr_handler => $on_stderr,
						wait_loop_callback => sub {
							my $now = time;
							if (($now - $last_out_at) >= $output_timeout) {
								$reason = "no output from `" . $cmdstr . "` in " . $output_timeout . "sec.";
								$ok = 0;
								kill 'HUP', $$;
							}
							if (!$verbose && $heartbeat && ($now - $last_heartbeat) >= $heartbeat) {
								$last_heartbeat = $now;
								say $description, ", ", ($now - $started), "sec.";
							}
						},
						terminate_on_signal => 'HUP',
						terminate_on_parent_sudden_death => 1,
						%params
					};
		$ok &&= !($resp->{killed_by_signal} || $resp->{exit_code});
		$buf = $resp->{merged};
	}
	else {
		($ok, $reason) = run( command => $cmd, %params, buffer => \$buf );
	}
	unless ($ok) {
		die "Command failed: " . ($reason || "No reason provided") . "\n";
	}
    return $buf;
}

sub parse_revision {
    my $rev       = shift;
    my $sep       = qr/[_.]/;
    my $rev_regex = qr/
        (?<year> \d+)
        $sep
        (?<month> \d+)
        (?:
            $sep
            (?<day> \d+)
        )?
        (?:
            -
            (?:
                (?<revno> \d+) - g[a-f0-9]*

                |

                RC (?<rcno> \d+)
            )
        )?
        $
    /x;
    if ( $rev =~ $rev_regex ) {
        return ( $+{year}, $+{month}, $+{day} // 0, $+{rcno} // 0,
            $+{revno} // 0 );
    }
    else {
        die "Unrecognized revision specifier '$rev'\n";
    }
}

sub cmp_rev {
    my ( $a, $b ) = @_;
    my @a   = parse_revision($a);
    my @b   = parse_revision($b);
    my $cmp = 0;
    for ( 0 .. 4 ) {
        $cmp = $a[$_] <=> $b[$_] if ( defined $a[$_] && defined $b[$_] );
        last if $cmp;
    }
    $cmp;
}

sub read_config_from_command {
    my $command = shift;
    my %config  = ();
    local $_;
    no warnings;
    if ( open my $CONFIG, '-|', $command ) {
        while (<$CONFIG>) {
            if (/^([^\s=]+)=(.*)/) { $config{$1} = $2 }
        }
        close($CONFIG);
    }
    return %config;
}

sub read_config {
    my @config_src = @_;
    my %config     = ();
    for my $file (@config_src) {
        if ( !-f $file ) {
            print STDERR "No pre-existing installed file found at $file\n";
            next;
        }
        %config = read_config_from_command("\"$file\" --show-config");
        last if %config;
    }
    return %config;
}

1;

# vim: ft=perl
