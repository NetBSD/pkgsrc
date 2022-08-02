$NetBSD: patch-Makefile.PL,v 1.1 2022/08/02 07:22:00 ast Exp $

Take Makefile.PL from version Math-Pari-2.01080900 to avoid
Math::PariBuild and other conflicting build rules

--- Makefile.PL.orig	2022-04-12 09:52:37.000000000 +0200
+++ Makefile.PL	2022-08-02 08:57:35.009435144 +0200
@@ -1,40 +1,10 @@
 # $Id: patch-Makefile.PL,v 1.1 2022/08/02 07:22:00 ast Exp $
-use strict;
-use Config '%Config';
-
-BEGIN {	# Need to do before ExtUtils::MakeMaker caches them
-  my $c = tied(%Config) || \%Config;
-  if ($Config{gccversion} and grep /^OPTIMIZE=.*(?<![^\s=])-g(?!\S)/,  @ARGV) {		# XXXX Bug in Perl configuration: these should be in {optimize} only
-    ($c->{"${_}flags"} = $Config{"${_}flags"}) =~ s/(?<!\S)-(s|O(\d+|s|fast)?)(?!\S)//g for qw(cc cpp ld lddl);
-  }							# gnukfreebsd(lddl) cygwin strawberry openbsd netbsd linux(lddl)
-  if ($^O eq 'solaris' and $Config{cc} eq 'gcc'
-      and (    ($c->{optimize}   = $Config{optimize})   =~ s/(?<!\S)(-xarch=386|-xildoff)(?!\S)//g
-            or ($c->{cccdlflags} = $Config{cccdlflags}) =~ s/(?<!\S)-KPIC(?!\S)/-fPIC/ )) {
-    # Vendor's Perl has major problems with building extensions; try to fix this
-    # One way is to use perlgcc; but it does not work with 5.8.4
-    # See http://prefetch.net/blog/index.php/2006/07/29/building-perl-modules-for-solaris/
-  print <<EOP;
-
-... Broken config of gcc-on-Solaris detected!  I would try to work around this.
-... Reset: cccdlflags --> '$Config{cccdlflags}',   optimize -> '$Config{optimize}'.
-
-EOP
-  }
-  ($c->{$_} = $Config{$_}) =~ s/(?<!\S)-flto(?!\S)// for qw(optimize $ldflags);
-}
-
 use ExtUtils::MakeMaker;
-
-BEGIN {unshift @INC, 'utils'}
-use Math::PariBuild;
+use Config '%Config';
 
 # Uncomment and change this line if I fail to find it
 # $paridir = "..";
 
-# Some testing machine may run out of disk space.  Bail out early.
-{ open my $f, '>', '.test.diskwrite' or die "Cannot open the file `./.test.diskwrite' for write: $! (Disk full???!)";
-}
-
 unless (-t STDOUT) {		# Better reports if run with redirections
     my $odef = select STDERR;
     $| = 1;
@@ -45,303 +15,63 @@
 
 chmod 0400, 'typemap' if $^O =~ /cygwin/ and -f 'typemap' and not -r 'typemap';	# bug in some installations of cygwin???
 
-my($ok23, $okPost23, $force_download, $force_patch, $parilib, $pariincludes, $parisrc, $paridir, $pari_version) = 1;
+my $pariprefix;
+my $addlibs;
+my $libpari = "pari";
 
-grep {/^machine=(.*)$/i		 and $common::machine = $1}  @ARGV;
-grep {/^configure$/i		 and $common::do_configure = 1}	     @ARGV;
-grep {/^paridir=(.*?)[\/\\]?$/i	 and $paridir = $1}	     @ARGV;
-grep {/^pari_tgz=(.*?)[\/\\]?$/i and $parisrc = $1}	     @ARGV;
-grep {/^force_download$/i	 and $force_download = 1}    @ARGV;
-grep {/^parilibs=(.*)$/i	 and $parilib = $1}	     @ARGV;
-grep {/^pariincludes=(.*)$/i	 and $pariincludes = $1}     @ARGV;
-grep {/^version23_ok=(.*)$/i	 and $ok23 = $1}	     @ARGV;
-grep {/^version_post23_ok=(.*)$/i and $okPost23 = $1}	     @ARGV;
-grep {/^force_patch(=\d+)?$/i	 and $force_patch = (defined $1 ? $1 : 1)}  @ARGV;
-# grep {/^OPTIMIZE=(?<![^\s=])-g(?!\S)/i	 and $dbg = 1}  @ARGV;	# -Og (= optimize what does not interfere with debug) needs -g
-
-# The REx should anchored-match versions to skip
-$common::skip_versions = $okPost23 ? '(?!)' : ($ok23 ? '2\.(?:[4-9]|\d\d+)\.' : '2\.(?:[3-9]|\d\d+)\.');
-
-@ARGV = grep !/^((machine|paridir|pari_tgz|parilibs|pariincludes|version23_ok|version_post23_ok|force_patch)=.*|configure|force_download)$/i, @ARGV;
-
-my %patchrc;
-
-$common::thread_engine = 'single';
-$common::src = ($^O =~ /^MSWin/i and $Config{ptrsize} == 8) ? 'src64' : 'src';
-
-my($extra_inc, $define, $libs);
-my $os = $Config{osname};
-if ($parilib) {
-  die "One should define `pariincludes' together with 'parilib'" unless defined $pariincludes;
-  $pari_version = pari_formatted_version_from_includes "$pariincludes/include";
-  $define = '-DNO_HIGHLEVEL_PARI -DUSE_STANDALONE_PARILIB';
-  print <<EOP;
-Trying to use existing PARI library (at $parilib)
-     (integer-formatted version $pari_version).
-EOP
-} else {
-  $paridir   = find_pari_dir() unless defined $paridir or $parisrc or $force_download;
-  ($paridir, my @patch_rc) = download_and_patch_pari($parisrc, $force_download)
-    if !$paridir or $force_download;
-
-die <<EOD  unless $paridir;
-Could not find GP/PARI build directory, please run Makefile.PL
-with paridir=/directory option.
-EOD
-
-  if (not $common::patches_run) {
-    if (-f (my $fn = "$paridir/.perl.patches")) {
-      my($h, @l, %s , $FAIL) = 0;
-      warn "\n\tIt looks like the directory was already patched.\n\tHere is the report from that patching session:\n",
-        do { if (open my $f, '<', $fn) {@l = <$f>}}, "\n";
-      if (@l) {
-        for my $l (@l) {
-          chomp $l;
-          $h = $1, next if $l =~ /^#\s*(\w+)/;
-          $s {$l}++ if $h eq 'Needed';
-          $FAIL++ if $h eq 'Failed';
-        }
-        $common::prepatched = \%s if keys %s;
-        $common::prepatched_fail = 1 if $FAIL;
-      }
-    } else {
-      my $force = (defined $force_patch ? $force_patch : ($paridir =~ m(^(\./)?pari)));
-      if ($force) {
-        @patch_rc = patch_pari($paridir);
-      } else {
-        warn "\n\tI won't auto-patch (`$paridir' is not a subdirectory) without option force_patch\n"
-      }
-    }
-  }
-  %patchrc = (patchrc => $patch_rc[0]) if @patch_rc;
+grep {/^pariprefix=(.*)$/i      and $pariprefix = $1}  @ARGV;
+grep {/^addlibs=(.*)$/i                 and $addlibs = $1}  @ARGV;
+grep {/^libpari=(.*)$/i                 and $libpari = $1}  @ARGV;
 
-  $define = '';
-  $pari_version = pari_formatted_version($paridir);
-  print <<EOP;
-Found GP/PARI build directory in $paridir
-     (integer-formatted version $pari_version).
-EOP
-  print <<EOP if $pari_version =~ /^20(\d\d)/ and $1 > 3;	# may have specified a particular tgz...
-
-  !!! Math::Pari does not support GP/PARI library versions after 2.3.*
-  !!!       (although many features work; see the file ./README-after2_3_5).
-  !!!   It seems you did force this particular version on Makefile.PL.
-  !!!   The build system should not pick up such a version by itself...
-
-EOP
-  print <<EOP if $pari_version =~ /^2003/ and not -f "$paridir/src/graph/plotgnuplot.c";
-
-  ### Math::Pari support of non-PS plotting functions of GP/PARI library
-  ### version 2.3.* requires patching GP/PARI source (I can auto-patch it).
-
-  ### It looks like auto-patching did not happen!
-
-EOP
-  print <<EOP if $pari_version =~ /^2003/;
-
-  ### In version 2.3.* of GP/PARI library, the test t/55_intnum.t takes
-  ###    significant time to complete.
-
-EOP
-  print <<EOP if $pari_version =~ /^2001/;
-
-  ### GP/PARI library version 2.1.* has many problems fixed in versions 2.3.*.
-
-  ### Especially important are the problems with symbols `hiremainder' and
-  ### `overflow' - if your build fails and error messages contain these
-  ### words, updating to 2.3.* might allow your use of fast processor-specific
-  ### assembler code.)
-
-  ### Switching to 2.3.* should be as simple as giving Makefile.PL an option
-  ###           version23_ok=1
-  ###   (if you or Makefile.PL already downloaded-and-extracted version-2.1.* 
-  ###    distribution, give an extra option, force_download).
-  ### Alternatively, give option
-  ###           paridir=DIRECTORY-of-extracted-distribution
-
-  ### However: v.2.3.* REQUIRES patching for full support of plotting.
-  ###   (And I can auto-patch it!)
-
-EOP
-  $common::pari_version = $pari_version;
-  $common::main_paridir = $paridir;
-  *MY::postamble = \&xMY::postamble;
-
-  my $gcc_version
-    = defined($Config{gccversion}) ? ", gccversion=$Config{gccversion}" : "";
-  print <<EOP;
-Setting up Math::Pari with Perl $] on $^O version $Config{osvers};
-   cc=$Config{cc}$gcc_version, cccdlflags='$Config{cccdlflags}',
-   ccflags='$Config{ccflags}',
-   optimize='$Config{optimize}',
-   ld=$Config{ld}, ldflags='$Config{ldflags}'.
-EOP
-
-  $define .= " -DPARI_VERSION_EXP=$pari_version -DDEBUG_PARI";
-  $define .= " -DUSE_SLOW_ARRAY_ACCESS -DUSE_SLOW_NARGS_ACCESS" if $] >= 5.009;
-  $libs = "-lm";
-  my $noexp2 = '';			# Should be used for generation of paricfg.h (not used anymore!)
-
-  if ($os eq "solaris") {
-    # Some older versions needed -lsunmath to import exp2().  This is
-    # probably not needed anymore (though can speed things up).
-
-    # Below -R specifies the path to search for this file when the
-    # program will run, -L the path to search when the program is linked
-  #  @sc_dirs = '/opt/SUNWspro/lib' if -d '/opt/SUNWspro/lib';
-  #  @sc_dirs = </opt/SUNWspro/SC*/lib> unless @sc_dirs;
-  #  if (@sc_dirs) {
-  #    $libs .= " -R$sc_dirs[-1] -L$sc_dirs[-1] -lsunmath -lm";
-  #  } else {
-  #    #warn "Cannot find SUNWspro dirs, needed for -lsunmath, using NOEXP2.\n";
-      $noexp2 = 1;
-  #  }
-  } elsif ($os eq "os2") {
-    $noexp2 = 1;
-    $define .= " -DMALLOC_PROCS";
-  } elsif ($os eq 'linux') {
-    $noexp2 = 1;
-  }
+@ARGV = grep !/^((pariprefix|addlibs|libpari)=.*)$/i, @ARGV;
+my $define = "-DPARI_VERSION_EXP=" . get_pari_formatted_version();
 
-  my %opts;
+# We want to find the offset of the least significant byte
+# of SV.flags inside an SV.
+# It is enough to find the offset of the least significant byte inside a U32.
+# (Needed for recognizing Perl code supplied to lisseq and lisexpr.)
 
-  build_tests $paridir;		# Convert the test suite
-  make_pod 'libPARI.pod', '-to_pod', $paridir; # Now the docs
-  make_pod 'libPARI.dumb.pod', '-to_dumb_pod', $paridir;
-  # ... and paricfg.h
-  %opts = build_paricfg($paridir, $common::do_configure, $pari_version);
-
-  if ($ENV{MATH_PARI_REPORT_CODES}) {
-    # Check the correspondence between string interfaces and numeric interfaces
-    my %codes;
-    my %names;
-    ep_in_version($pari_version);
-    ep_codes_from_file("$paridir/src/language/init.c", %codes, %names);
-    ep_codes_from_file("$paridir/src/gp/highlvl.c", %codes, %names);
-    # EpValence reworked in 2.2.7; when exactly was it redone???  XXXX
-    unless ($pari_version > 2002006 or ep_hash_report(%codes)) {
-      print STDERR "Problems with numeric interface codes noted:\n";
-      ep_hash_report(%codes, %names, \*STDERR);
-    }
-  }
+$offset = index($Config{byteorder}, "1");
+$offset = 3 if $offset > 3;	# SvFLAGS is actually I32
+$define .= " -DLSB_in_U32=$offset";
 
-  # We want to find the offset of the least significant byte
-  # of SV.flags inside an SV.
-  # It is enough to find the offset of the least significant byte inside a U32.
-  # (Needed for recognizing Perl code supplied to lisseq and lisexpr.)
-
-  my $offset = index($Config{byteorder}, "1");
-  $offset = 3 if $offset > 3;	# SvFLAGS is actually I32
-  $define .= " -DLSB_in_U32=$offset";
-
-  my $longsize = length(eval { pack 'l!', 1 } or pack 'l', 1);
-  my $perl_int_size = $Config{'ivsize'} || $Config{'intsize'}
-          or die "Can't deduce Perl int size";
-
-  $define .= ' -DLONG_SHORTER_THAN_IV' if $perl_int_size > $longsize and $common::src eq 'src';	# no hack
-
-  $define .= ' -Derr=pari_err'; # On linux it can get a wrong dynamic loading
-  $define .= ' -DHAVE_LADD' if $opts{have_ladd};
-  $define .= ' -DGCC_INLINE' if $Config{gccversion} and not $Config{optimize} =~ /-g\b/;
-  $define .= ' -DHAVE_PARIPRIV' if -f "$paridir/src/headers/paripriv.h";
-  $define .= ' -DNO_GRAPHICS_PARI' unless -f "$paridir/src/graph/plotgnuplot.c";	# present before 2.2.13; we can patch it in 
-
-  # XXXX otherwise segfaults trying to install highlevel functions???
-  # XXXX because functions_hash = NULL???
-  # $define .= ' -DNO_HIGHLEVEL_PARI' if $pari_version >= 2003000;
-  # $define .= ' -DNO_GRAPHICS_PARI' if $pari_version >= 2003000;
+my $longsize = length(eval { pack 'l!', 1 } or pack 'l', 1);
+my $perl_int_size = $Config{'ivsize'} || $Config{'intsize'}
+	or die "Can't deduce Perl int size";
 
-  # This is done in Makefile in GP/PARI, and in paricfg.h without do_configure
-  $define .= ' -DDL_DFLT_NAME=NULL' if $common::do_configure;
+$define .= ' -DLONG_SHORTER_THAN_IV' if $perl_int_size > $longsize;
 
-  $extra_inc = extra_includes($paridir);
-}
+$define .= ' -Derr=pari_err'; # On linux it can get a wrong dynamic loading
+$define .= ' -DGCC_INLINE' if $Config{gccversion} and not $Config{optimize} =~ /-g\b/;
+
+$define .= " -DNO_HIGHLEVEL_PARI";
 
-(my $paridir_v = $paridir) =~ s{^(.*[\\/])?pari\W*}();
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile being created.
 &WriteMakefile(
+	       LIBS	     =>  join( " ", "-L${pariprefix}/lib -l${libpari}", $addlibs ),
+	       INC	     => $extra_inc . " -I ${pariprefix}/include -I ${pariprefix}/src",
 	       NAME	     => 'Math::Pari',
-	       ($parilib ? (
-		  LIBS	     =>  $parilib,
-		  INC	     =>  "-I $pariincludes/include -I $pariincludes/src",
-		 ) :
-		 (MYEXTLIB   =>  'libPARI/libPARI$(LIB_EXT)')),
-		  LIBS	     =>  $libs,
-		  INC	     =>  $extra_inc . ' -I $(PARI_DIR_SRC)/headers -I $(PARI_DIR_SRC) -I ./libPARI',
 	       VERSION_FROM  => 'Pari.pm',
     ($] >= 5.005 ?     ## Add these new keywords supported since 5.005
       (ABSTRACT_FROM  => 'Pari.pm', # retrieve abstract from module
        AUTHOR         => 'Ilya Zakharevich <ilyaz@cpan.org>') : ()),
 	       DEFINE	     => $define,
 	       dist	     => {COMPRESS=>'gzip -9f', SUFFIX=>'gz'},
-	       clean	     => { FILES => 'pari.ps test_eng/ex.t- libPARI.dumb.pod libPARI.pod t/55_*.t ftp-cmd .test.diskwrite tst-run-* t/tst-run-* dbg-bld dbg-bldO' },
-	       macro	     => { %patchrc,
-				  PARI_DIR	  => $paridir,
-				  PARI_DIR_SRC	  => "$paridir/$common::src",
-				  PARI_DIR_VER	  => $paridir_v,
-				},
-#		($ExtUtils::MakeMaker::VERSION >= 6.3002 ? (LICENSE  => 'perl' ) : ()),	# gpl_3 in libPARI
-              META_ADD => {    license => [ qw(perl_5 gpl_2) ],  },
 	      );
 
-if (not $common::patches_run or @common::patches_fail) {
-  my @patches_needed = patches_for($pari_version);
-  my $msg = $common::patches_run ? "failed when applied" : "were not applied";
-  push @common::patches_fail, @patches_needed unless $common::patches_run;
-  my @miss = @common::patches_fail;
-  @miss = grep !$common::prepatched->{$_}, @common::patches_fail if $common::prepatched;
-  my $but = $common::prepatched ?
-        (@miss ? "\n   (Some - but not all - patches were " : "\n   (All these patches were successfully ")
-          . 'auto-applied in an earlier build; see above for a report.)' : '';
-  warn "\nThe following patches were judged to be beneficial, but $msg:\n\t@common::patches_fail (out of @patches_needed)$but\n"
-    if @common::patches_fail;
-}
-
-# Allow easy editing more stuff in libPARI
-sub MY::subdirs_NONONO # disabled: too fragile
+sub get_pari_formatted_version()
 {
- my $self = shift;
- (my $sec = $self->MM::subdirs)		# Try to change the first occurence
-    =~ s/^(subdirs(?:_pure_nolink)?\s*::(?![^\n\S]*subdirs-make\b)[^\n\S]*)/$1 subdirs-make\n\nsubdirs-make :: /m ;
- $sec;
-}
-
-# Allow easy editing more stuff in libPARI
-sub MY::dynamic				# 5.22 (?) starts to put subdirs_dynamic as a dependence on dynamic
-{
- my $self = shift;
- (my $sec = $self->MM::dynamic)		# Try to fix
-    =~ s/^(dynamic\s*::.*\s)subdirs_dynamic(?!\S)/$1/m ;
- $sec;
-}
-
-# Remake POD if the source changed.
-# Go to a subdirectory to build the headers and the library.
-# XXX With -j4 goes twice to a subdir in parallel, both times without -j4...
-sub xMY::postamble {
-  '
-AUTOGEN_HEADERS = libPARI/pariinl.h
-
-Pari$(OBJ_EXT) : $(AUTOGEN_HEADERS)
-
-$(AUTOGEN_HEADERS) $(MYEXTLIB): subdirs-make FORCE
-
-subdirs-make: libPARI/$(FIRST_MAKEFILE)
-	cd libPARI && $(MAKE) $(PASTHRU)
-
-
-libPARI.pod: $(PARI_DIR)/doc/usersch3.tex libPARI/gphelp
-	$(PERL) libPARI/gphelp -to_pod -pari-version=$(PARI_DIR_VER) $(PARI_DIR)/doc/usersch3.tex > pod_tmp && mv pod_tmp $@
-
-libPARI.dumb.pod: $(PARI_DIR)/doc/usersch3.tex libPARI/gphelp
-	$(PERL) libPARI/gphelp -to_dumb_pod -pari-version=$(PARI_DIR_VER) $(PARI_DIR)/doc/usersch3.tex > pod_tmp && mv pod_tmp $@
-
-build_tests:
-	-$(RM_F) test_eng/ex.t-
-	$(FULLPERL) -Iutils -MMath::PariBuild -e "build_tests shift" $(PARI_DIR)
-
-';
+    my $fh;
+    my $formatted_version;
+    open( $fh, "<", "${pariprefix}/include/pari/paricfg.h" ) or die $!;
+    while( my $line = <$fh> )
+    {
+       next unless ( $line =~ m/^#define\s+PARIVERSION.*(\d+)\.(\d+)\.(\d+)/ );
+       $formatted_version = sprintf( "%d%03d%03d", $1, $2, $3 );
+    }
+    close($fh);
+    return $formatted_version;
 }
 
 # Rewrite pic option to PIC in CCCDLFLAGS,
@@ -351,8 +81,8 @@
  my $self = shift;
  my $flags = $self->{'CCCDLFLAGS'}; # Tmp var needed with Perl4 !
  $flags =~ s/(-[fK]?\s*)pic\b/${1}PIC/; 
- $flags =~ s/-KPIC/-K PIC/	# Apparently (was?) needed on Solaris... (But see http://gnats.netbsd.org/45271)
-   if $os eq 'solaris' and not ($Config{cc} eq 'gcc' and $Config{gccversion} ge '4.6');	# without "parilib", changed to fPIC earlier
+ # Nowadays breaks build; see PR 45271
+ #$flags =~ s/-KPIC/-K PIC/;	# Apparently (was?) needed on Solaris...
  $self->{'CCCDLFLAGS'} = $flags;
  if ($^O eq 'MSWin32' && $Config{'ccflags'} =~ /-DPERL_OBJECT/)
   {
