# $NetBSD: Policy.sh,v 1.5 2012/11/07 03:58:00 sbd Exp $
#
# Site-wide policy settings for pkgsrc Perl
#
archname='@MACHINE_ARCH@-@LOWER_OPSYS@'
cc='@CC@'
ccflags='@CFLAGS@'
ldflags='@LDFLAGS@'
if $test -n "$ccflags"; then
	optimize="$ccflags"
fi
i_malloc='undef'
installusrbinperl='undef'
installstyle='lib/perl5'

# Perl embeds the full paths to the following tools in several installed
# files, so make sure the paths to the ones in ${TOOLS_DIR} aren't used.
aphostname='@TOOLS_HOSTNAME_CMD@'
ln='@TOOLS_LN@'
lns='@TOOLS_LN@ -s'
sed='@TOOLS_SED@'
sh='@TOOLS_SH@'
issymlink='@TOOLS_TEST@ -h'
perl5='@FALSE@'

# Installation directories for "perl", "vendor" and "site" bits.
prefix='@PERL5_PREFIX@'
siteprefix='@PERL5_SITEPREFIX@'
vendorprefix='@PERL5_VENDORPREFIX@'

# The Perl Configure script will install scripts into "*/script"
# directories if they exist, so override with explicit settings.
scriptdir='@PERL5_PERLBASE@/bin'
sitescript='@PERL5_SITEBASE@/bin'
vendorscript='@PERL5_VENDORBASE@/bin'

# Put any compiled binaries into vendor- and site-specific locations to
# avoid conflicts with each other.  The perllink script will handle all
# the appropriate symlinking.
sitebin='@PERL5_SITEBIN@'
vendorbin='@PERL5_VENDORBASE@/bin'

# Put the API-specific files into API-specific directories instead
# of the default version-specific directories.
privlib='@PERL5_PRIVLIB@'
sitelib='@PERL5_SITELIB@'
vendorlib='@PERL5_VENDORLIB@'

# Search for version-specific directories under these directories.
sitelib_stem='@PERL5_SITEBASE@'
vendorlib_stem='@PERL5_VENDORBASE@'

# Avoid manpage conflicts between the standard Perl library, 3rd-party
# modules, and other packages.
man1ext='1'
man1dir='@PERL5_PERLBASE@/@PKGMANDIR@/man1'
siteman1dir='@PERL5_SITEBASE@/@PKGMANDIR@/man1'
vendorman1dir='@PERL5_VENDORBASE@/@PKGMANDIR@/man1'
man3ext='3'
man3dir='@PERL5_PERLBASE@/@PKGMANDIR@/man3'
siteman3dir='@PERL5_SITEBASE@/@PKGMANDIR@/man3'
vendorman3dir='@PERL5_VENDORBASE@/@PKGMANDIR@/man3'

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
if $test -n "@LIBSWANTED@"; then
	libswanted="@LIBSWANTED@ "
fi

# Add the pkgsrc-derived LDFLAGS for linking against pthreads to the
# usethreads.cbu call-back script
if $test -n "@PTHREAD_LDFLAGS@"; then
	cat >> UU/usethreads.cbu <<EOCBU

# Add pkgsrc-derived ldflags to link with thread support.
ldflags="@PTHREAD_LDFLAGS@ \$ldflags"
lddlflags="@PTHREAD_LDFLAGS@ \$lddlflags"
EOCBU
fi

# Generate a pkgsrc.cbu call-back script that sets the correct LDFLAGS
# for linking against pkgsrc-installed libraries
cat > UU/pkgsrc.cbu <<EOCBU
# This script UU/pkgsrc.cbu will get 'called-back' by Configure
# *after* all hints

# XCOFF targets need the path specified where libperl.a resides.
if $test "@OBJECT_FMT@" = "XCOFF"; then
	ldflags="@COMPILER_RPATH_FLAG@\${shrpdir} \$ldflags"
	lddlflags="@COMPILER_RPATH_FLAG@\${shrpdir} \$lddlflags"
fi

# Set pkgsrc defaults for library and header search paths:
# nail down the directories in which headers and libraries of
# locally-installed software may be found.
loclibpth="@LOCALBASE@/lib"
locincpth="@LOCALBASE@/include"

# Set pkgsrc defaults for "plateform"/general path used to 
# find libraries
if $test -n "@SYSLIBPATH@"; then
	glibpth="@SYSLIBPATH@"
fi

# Strip /usr/local/lib... from ldflags
case "\$ldflags" in */usr/local/lib*)
	set \`echo "X \$ldflags " | sed 's, [^ ]*/usr/local/lib[^ ]* , ,g'\`
	shift
	ldflags="\$*"
	;;
esac

# Strip gdbm from libswanted
case "\$libswanted" in *gdbm*)
	set \`echo "X \$libswanted " | sed 's, [^ ]*gdbm[^ ]* , ,g'\`
	shift
	libswanted="\$*"
esac

# (re)Set sed here so that sed _and_ full_sed are correctly *both* set
sed='@TOOLS_SED@'
EOCBU
