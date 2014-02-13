#!@PERL5@ -w

use strict;
use warnings;
use 5.010;

use Carp qw(carp croak);
use Cwd qw(abs_path);
use File::Basename;
use File::Spec;
use version;
use File::Find::Rule;
use Getopt::Long;
use Pod::Usage qw(pod2usage);

use CPAN;
use CPAN::DistnameInfo;
use Module::CoreList;

package PkgP5UpToDate::AsciiWriter;

sub new
{
    my ($class, $filename) = @_;
    my %inst;
    open( $inst{fh}, '>', $filename ) or die "Can't open $filename for writing: $!";
    return bless( \%inst, $_[0] );
}

sub DESTROY
{
    defined( $_[0]->{finished} ) or $_[0]->finish();
    defined( $_[0]->{fh} ) and close( $_[0]->{fh} );
}

sub init
{
}

sub write_entry
{
    my ($self, $pkgloc, $maint, $comment, $distver, $op, $pkgver, $installed) = @_;
    $installed = $installed ? " (I)" : "";
    say {$self->{fh}} $pkgloc . " (" . $maint . ") $comment: ". $distver . " $op " . $pkgver . $installed;
    return;
}

sub finish
{
    my ($self, $pkg2update, $pkgok, $pkgcrank) = @_;
    scalar(@_) > 1 and
      say {$self->{fh}} "$pkg2update p5-packages needing updates, $pkgok p5-packages are up-to-date, $pkgcrank p5-packages needs review";
    $self->{finished} = 1;
    return;
}

package PkgP5UpToDate::HtmlWriter;

our @ISA = ('PkgP5UpToDate::AsciiWriter');

sub init
{
    my $self = $_[0];
    my $intro = <<EOH;
<html>
<head>
  <title>Outdated Perl5 modules in pkgsrc</title>
</head>

<body>
  <h1>Outdated Perl5 modules in pkgsrc</h1>
  <table>
    <tr><th>Package location</th><th>Maintainer</th><th>Comment</th><th>Operation</th><th>Installed</th></tr>
EOH
    say {$self->{fh}} $intro;
    return;
}

sub write_entry
{
    my ($self, $pkgloc, $maint, $comment, $distver, $op, $pkgver, $installed) = @_;
    $op =~ s/</&lt;/;
    $op =~ s/>/&gt;/;
    my $line = sprintf( "    <tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>",
                        $pkgloc, $maint, $comment, $distver . " $op " . $pkgver, $installed ? "Yes" : "-" );
    say {$self->{fh}} $line;
    return;
}

sub finish
{
    my ($self, $pkg2update, $pkgok, $pkgcrank) = @_;
    say {$self->{fh}} "  </table>";
    scalar(@_) > 1 and
      say {$self->{fh}} "$pkg2update p5-packages needing updates, $pkgok p5-packages are up-to-date, $pkgcrank p5-packages needs review";
    my $extro = <<EOE;
</body>
</html>
EOE
    say {$self->{fh}} $extro;
    return;
}

package main;

my $make_bin = '@MAKE@';
my $pkg_info_bin = '@PKG_INFO_CMD@';

sub is_gt
{
    my $gt;
    defined($_[0]) and $_[0] =~ /^v/ and $_[1] !~ /^v/ and $_[1] = "v$_[1]";
    defined($_[0]) and $_[0] !~ /^v/ and $_[1] =~ /^v/ and $_[0] = "v$_[0]";
    eval {
	$gt = defined( $_[0] ) && (version->parse($_[0]) > version->parse($_[1]));
    };
    if( $@ ) {
	$gt = defined( $_[0] ) && ($_[0] gt $_[1]);
    }
    return $gt;
}

sub is_ne
{
    my $ne;
    defined($_[0]) and $_[0] =~ /^v/ and $_[1] !~ /^v/ and $_[1] = "v$_[1]";
    defined($_[0]) and $_[0] !~ /^v/ and $_[1] =~ /^v/ and $_[0] = "v$_[0]";
    eval {
	$ne = defined( $_[0] ) && (version->parse($_[0]) != version->parse($_[1]));
    };
    if( $@ ) {
	$ne = defined( $_[0] ) && ($_[0] ne $_[1]);
    }
    return $ne;
}

sub get_pkg_vars
{
    my $varnames = join( " ", @_ );
    my @vals = qx($make_bin show-vars VARNAMES="$varnames");  chomp @vals;
    return @vals;
}

sub get_inst_pkgs
{
    my $fh;
    open( $fh, "$pkg_info_bin |" ) or die "Can't exec pkg_info: $!";
    my @havepkgs = <$fh>;
    close( $fh ) or die "Can't close pipe to pkg_info: $!";
    chomp @havepkgs;
    @havepkgs = map { ( split( m/\s+/, $_ ) )[0] } grep { 0 == index( $_, 'p5-' ) } @havepkgs;
    my %havepkgs = map { $_ => 1 } @havepkgs;

    return %havepkgs;
}

sub get_cpan_versions
{
    my $update_idx = $_[0];

    defined( $update_idx ) and $update_idx and
      $CPAN::Index::LAST_TIME = 0;
    CPAN::Index->reload( defined( $update_idx ) and $update_idx );
    $CPAN::Index::LAST_TIME or
      carp( "Can't reload CPAN Index" );

    my @all_dists = $CPAN::META->all_objects( "CPAN::Distribution" );
    my %pkgdist;

    foreach my $dist (@all_dists)
    {
        my $dinfo = CPAN::DistnameInfo->new( $dist->id() );
	my ($distname, $distver) = ($dinfo->dist(), $dinfo->version());
	defined( $distname ) or next;
	defined( $distver ) or next;
        if( !defined( $pkgdist{$distname} ) || ( defined( $pkgdist{$distname} ) && is_gt( $distver, $pkgdist{$distname} ) ) )
        {
            $pkgdist{$distname} = $distver;
        }
    }

    return %pkgdist;
}

sub get_modules_by_distribution
{
    CPAN::Index->reload();
    $CPAN::Index::LAST_TIME or
      carp( "Can't reload CPAN Index" );

    my @all_modules = $CPAN::META->all_objects( "CPAN::Module" );
    my %modsbydist;

    foreach my $module (@all_modules)
    {
	my $modname = $module->id();
	$module->cpan_version() or next;
	my $distfile = $module->cpan_file();
        my $dinfo = CPAN::DistnameInfo->new( $distfile );
	my ($distname, $distver) = ($dinfo->dist(), $dinfo->version());
	defined( $distname ) or next;
	defined( $distver ) or next;
	$modsbydist{$distname} //= [];
	push( @{$modsbydist{$distname}}, $modname );
    }

    return %modsbydist;
}

sub find_pkgsrc_dir
{
    defined( $ENV{PKGSRCDIR} ) and return $ENV{PKGSRCDIR};

    foreach my $dir (qw(@PKGSRCDIR@ . .. ../.. /usr/pkgsrc))
    {
        -d $dir and -f File::Spec->catfile( $dir, "mk", "bsd.pkg.mk" )
          and return abs_path($dir); # Cwd::abs_path()
    }

    return;
}

my %writers = (
    ascii => 'PkgP5UpToDate::AsciiWriter',
    html => 'PkgP5UpToDate::HtmlWriter',
);

my %opts = (
  "output-fmt" => "ascii",
  "output-file" => File::Spec->catfile( $ENV{HOME}, "p5up2date.log" ),
  "scan-installed" => 1,
  "update-cpan-index" => 0,
);
GetOptions(
  \%opts,
  "cpan-home=s",
  "output-fmt=s",
  "output-file=s",
  "scan-installed!",
  "update-cpan-index!",
  "help|h",
  "usage|?"
) or pod2usage(2);

defined( $opts{help} ) and $opts{help} and pod2usage( { -verbose => 2, -exitval => 0 } );
defined( $opts{usage} ) and $opts{usage} and pod2usage(1);
defined( $writers{$opts{'output-fmt'}} ) or pod2usage( { -verbose => 1, -exitval => 1, -message => 'Unknown output format' } );

if( defined($opts{"cpan-home"}) and -e File::Spec->catfile( $opts{'cpan-home'}, 'CPAN', 'MyConfig.pm' ) )
{
    my $file = File::Spec->catfile( $opts{'cpan-home'}, 'CPAN', 'MyConfig.pm' );

    # XXX taken from App:Cpan::_load_config()
    $CPAN::Config = {};
    delete $INC{'CPAN/Config.pm'};

    my $rc = eval "require '$file'";

    # CPAN::HandleConfig::require_myconfig_or_config looks for this
    $INC{'CPAN/MyConfig.pm'} = 'fake out!';

    # CPAN::HandleConfig::load looks for this
    $CPAN::Config_loaded = 'fake out';

    croak( "Could not load [$file]: $@\n") unless $rc;
}
else
{
    CPAN::HandleConfig->load();
    defined( $opts{"cpan-home"} ) and -d $opts{"cpan-home"} and
      $CPAN::Config{cpan_home} = $opts{'cpan-home'}
}

$CPAN::Config_loaded or die "Can't load CPAN::Config - please setup CPAN first";

my %havepkgs;
$opts{"scan-installed"} and %havepkgs = get_inst_pkgs();

my $writer = $writers{$opts{'output-fmt'}}->new( $opts{'output-file'} );
$writer->init();

my %pkgdist = get_cpan_versions( $opts{'update-cpan-index'} );
my %distmods = get_modules_by_distribution();

my ( $pkg2update, $pkgok, $pkgcrank ) = ( 0, 0, 0 );

my $pkgsrc_base = find_pkgsrc_dir();
my @p5_pkg_dirs = find( directory => name => "p5-*", in => $pkgsrc_base );
   @p5_pkg_dirs = sort @p5_pkg_dirs;

foreach my $dn (@p5_pkg_dirs)
{
    chdir( $dn );
    my ($distnm, $extract_sufx, $pkgnm, $maint ) = get_pkg_vars( qw(DISTNAME EXTRACT_SUFX PKGNAME MAINTAINER) );
    my $pkgver = 0;
    if( $distnm =~ m/^(.*)-(v?[0-9].*?)$/ )
    {
        $distnm = $1;
        $pkgver = $2;
    }
    if( defined( $pkgdist{$distnm} ) && ($pkgdist{$distnm} =~ m/^(.*)$extract_sufx$/ ) )
    {
        $pkgdist{$distnm} = $1;
    }

    my @mods = map { @{$distmods{$_}} } grep { $_ =~ m/^$distnm/ } keys %distmods;
    foreach my $distmod (@{mods})
    {
	my $mod = $CPAN::META->instance( "CPAN::Module", $distmod );
	if( is_gt( $Module::CoreList::version{$]}->{$distmod}, $mod->cpan_version() ) )
	{
	    (my $pkgdir  = $dn) =~ s,$pkgsrc_base/,,;
	    $writer->write_entry( File::Spec->catfile( $pkgdir, $pkgnm ), $maint, "is older than core for $distmod", $Module::CoreList::version{$]}->{$distmod}, ">", $mod->cpan_version(), defined( $havepkgs{$pkgnm} ) );
	    ++$pkgcrank;
	    last;
	}
    }

    if( is_gt($pkgdist{$distnm}, $pkgver ) )
    {
        (my $pkgdir  = $dn) =~ s,$pkgsrc_base/,,;
	$writer->write_entry( File::Spec->catfile( $pkgdir, $pkgnm ), $maint, "need update", $pkgdist{$distnm}, ">", $pkgver, defined( $havepkgs{$pkgnm} ) );
	++$pkg2update;
    }
    elsif( is_ne($pkgdist{$distnm}, $pkgver ) )
    {
        (my $pkgdir  = $dn) =~ s,$pkgsrc_base/,,;
	$writer->write_entry( File::Spec->catfile( $pkgdir, $pkgnm ), $maint, "out of sync?", $pkgdist{$distnm}, "!=", $pkgver, defined( $havepkgs{$pkgnm} ) );
	++$pkgcrank;
    }
    else
    {
	++$pkgok;
    }
}

$writer->finish( $pkg2update, $pkgok, $pkgcrank );

exit( 0 );

=pod

=head1 NAME

pkg_p5up2date - check p5-* pkgsrc packages whether being up-to-date or need updating

=head1 SYNOPSIS

  pkg_p5up2date [--cpan-home <dir>] [--output-fmt <ascii|html>]
		[--output-file <filename>]
                [--[no-]scan-installed] [--[no-]update-cpan-index]
                [--help] [--usage]

=head1 DESCRIPTION

This script scans pkgsrc directory for outdated cpan packages.
Packages which will need updates are listed and packages which are
newer than their cpan pendants are reported as "needs review".

=head1 OPTIONS

=over 8

=item C<--cpan-home>

Specifies home directory for cpan configuration and cache.
Loads following files:

  ${cpan-home}/CPAN/MyConfig.pm
  ${cpan-home}/sources/modules/02packages.details.txt.gz

=item C<--output-fmt>

Let you choose the output format, either I<ascii> or I<html>.

Default is ascii.

=item C<--output-file>

Let you specify another target file then C<~/p5up2date.log> for
writing packages which needs attention.

=item C<--scan-installed|--no-scan-installed>

Specifies whether installed packages shall be marked explicitely.

=item C<--update-cpan-index|--no-update-cpan-index>

Specifies whether cpan index cache shall be forced to update or not.

=item C<--help>

Prints help and exit.

=item C<--usage>

Prints usage and exit.

=back

=head1 AUTHOR

Jens Rehsack <sno@NetBSD.org>

=cut
