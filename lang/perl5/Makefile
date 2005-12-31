# $NetBSD: Makefile,v 1.109.2.2 2005/12/31 19:47:07 seb Exp $

# The following two variables should have empty values unless we're
# building a perl snapshot or release candidate.
#
PERL5_SNAPSHOT=	# empty
PERL5_RC_VERS=	# empty

PERL5_VERS=	5.8.7
CATEGORIES=	lang devel perl5
EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/${DISTNAME}

.if empty(PERL5_SNAPSHOT) && empty(PERL5_RC_VERS)
DISTNAME=	perl-${PERL5_VERS}
PKGNAME=	perl-${PERL5_VERS}
PKGREVISION=	6
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S,/modules/by-module/$,/src/,}
.else
.  if !empty(PERL5_SNAPSHOT)
DISTNAME=	perl@${PERL5_SNAPSHOT}
PKGNAME=	perl-${PERL5_VERS}beta${PERL5_SNAPSHOT}
MASTER_SITES=	http://www.iki.fi/jhi/
EXTRACT_SUFX=	.tbz
WRKSRC=		${WRKDIR}/perl
.  else # !empty(PERL5_RC_VERS)
DISTNAME=	perl-${PERL5_VERS}-RC${PERL5_RC_VERS}
PKGNAME=	perl-${PERL5_VERS}rc${PERL5_RC_VERS}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/J/JH/JHI
.  endif
.endif

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.perl.com/
COMMENT=	Practical Extraction and Report Language

CONFLICTS=	perl-base-[0-9]* perl-thread-[0-9]*			\
		p5-CGI-2.66 p5-CGI-2.75 p5-CGI-2.75.[0-2]

.include "../../mk/bsd.prefs.mk"

# Determine the Perl API version from the patchlevel.h file from the
# source distribution.
#
PERL5_API_VERS?=	unknown
.if exists(${WRKSRC}/patchlevel.h)
PERL5_API_VERS_cmd=							\
	${AWK} '/\#define[ 	]*PERL_API_REVISION/ { R = $$3 }	\
		/\#define[ 	]*PERL_API_VERSION/ { r = "."$$3 }	\
		/\#define[ 	]*PERL_API_SUBVERSION/ { s = "."$$3 }	\
		END { printf "%s%s%s\n", R, r, s }'			\
		${WRKSRC}/patchlevel.h
PERL5_API_VERS=		${PERL5_API_VERS_cmd:sh}
.endif

PERL5_PREFIX=		${PREFIX}
PERL5_VENDORPREFIX=	${PERL5_PREFIX}
PERL5_SITEPREFIX?=	${PERL5_PREFIX}
BUILD_DEFS+=		PERL5_SITEPREFIX

PERL5=			${PERL5_PREFIX}/bin/perl
PERL5_PERLBASE=		${PERL5_PREFIX}/lib/perl5
PERL5_VENDORBASE=	${PERL5_VENDORPREFIX}/lib/perl5/vendor_perl
#
# The unusual check for empty(PERL5_SITEPREFIX) is because ${PREFIX} isn't
# defined until bsd.pkg.mk is included, so when we inspect its value at
# this point, it's empty.
#
.if empty(PERL5_SITEPREFIX) || \
    !empty(PERL5_SITEPREFIX:M${LOCALBASE}) || \
    !empty(PERL5_SITEPREFIX:M${LOCALBASE}/*)
PERL5_SITEBASE=		${PERL5_SITEPREFIX}/lib/perl5/site_perl
.else
PERL5_SITEBASE=		${PERL5_SITEPREFIX}
.endif

PERL5_PRIVLIB=		${PERL5_PERLBASE}/${PERL5_API_VERS}
PERL5_VENDORLIB=	${PERL5_VENDORBASE}/${PERL5_API_VERS}
.if !empty(PERL5_SITEBASE:M*lib/perl5/site_perl)
PERL5_SITELIB=		${PERL5_SITEBASE}/${PERL5_API_VERS}
.else
PERL5_SITELIB=		${PERL5_SITEBASE}/lib/perl5/site_perl/${PERL5_API_VERS}
.endif

.include "../../mk/compiler.mk"

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Dcc=${CC:Q}
CONFIGURE_ARGS+=	-Doptimize=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	-Duseshrplib
CONFIGURE_ARGS+=	-Ui_malloc
CONFIGURE_ARGS+=	-Uusemymalloc
CONFIGURE_ARGS+=	-Uinstallusrbinperl
MAKE_ENV+=		LC_ALL="C"

TEST_TARGET=		test

###
### Installation directories for "perl", "vendor" and "site" bits.
###
CONFIGURE_ARGS+=	-Dinstallstyle="lib/perl5"
CONFIGURE_ARGS+=	-Dprefix=${PERL5_PREFIX:Q}
CONFIGURE_ARGS+=	-Dsiteprefix=${PERL5_SITEPREFIX:Q}
CONFIGURE_ARGS+=	-Dvendorprefix=${PERL5_VENDORPREFIX:Q}

# The Perl Configure script will install scripts into "*/script"
# directories if they exist, so override with explicit settings.
#
CONFIGURE_ARGS+=	-Dscriptdir=${PERL5_PERLBASE:Q}/bin
CONFIGURE_ARGS+=	-Dsitescript=${PERL5_SITEBASE:Q}/bin
CONFIGURE_ARGS+=	-Dvendorscript=${PERL5_VENDORBASE:Q}/bin

# Put the API-specific files into API-specific directories instead
# of the default version-specific directories.
#
CONFIGURE_ARGS+=	-Dprivlib=${PERL5_PRIVLIB:Q}
CONFIGURE_ARGS+=	-Dsitelib=${PERL5_SITELIB:Q}
CONFIGURE_ARGS+=	-Dvendorlib=${PERL5_VENDORLIB:Q}

# Avoid manpage conflicts between the standard Perl library, 3rd-party
# modules, and other packages.
#
CONFIGURE_ARGS+=	-Dman1ext="1"
CONFIGURE_ARGS+=	-Dman1dir=${PERL5_PERLBASE:Q}/man/man1
CONFIGURE_ARGS+=	-Dsiteman1dir=${PERL5_SITEBASE:Q}/man/man1
CONFIGURE_ARGS+=	-Dvendorman1dir=${PERL5_VENDORBASE:Q}/man/man1
CONFIGURE_ARGS+=	-Dman3ext="3"
CONFIGURE_ARGS+=	-Dman3dir=${PERL5_PERLBASE:Q}/man/man3
CONFIGURE_ARGS+=	-Dsiteman3dir=${PERL5_SITEBASE:Q}/man/man3
CONFIGURE_ARGS+=	-Dvendorman3dir=${PERL5_VENDORBASE:Q}/man/man3

.if ${OPSYS} == "Darwin"
#
# The Perl build attempts to work around case-insensitivity problems on
# HFS filesystems by using GNUmakefiles, so we need to use GNU make.
#
USE_TOOLS+=	gmake
.endif

# Perl embeds the full paths to the following tools in several installed
# files, so make sure the paths to the ones in ${TOOLS_DIR} aren't used.
#
USE_TOOLS+=		hostname ln sed test
CONFIGURE_ARGS+=	-Daphostname=${TOOLS_HOSTNAME_CMD:Q}
CONFIGURE_ARGS+=	-Dln=${TOOLS_LN:Q}
CONFIGURE_ARGS+=	-Dsed=${TOOLS_SED:Q}
CONFIGURE_ARGS+=	-Dissymlink="${TOOLS_TEST} -h"

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.Darwin=	m c
LIBSWANTED.DragonFly=	m crypt
LIBSWANTED.FreeBSD=	m crypt
LIBSWANTED.IRIX=	m crypt
LIBSWANTED.Interix=	m dl
LIBSWANTED.NetBSD=	m crypt
LIBSWANTED.OpenBSD=	m crypt
LIBSWANTED.SunOS=	m crypt dl socket nsl
LIBSWANTED=		${LIBSWANTED.${OPSYS}}

# Nail down the directories in which the system libraries may be found.
# If this isn't defined, then use the perl defaults for the particular
# operating system.
#
SYSLIBPATH.Darwin=	/usr/lib
SYSLIBPATH.DragonFly=	/usr/lib
SYSLIBPATH.FreeBSD=	/usr/lib
SYSLIBPATH.Interix=	/usr/lib
SYSLIBPATH.NetBSD=	/usr/lib
SYSLIBPATH.OpenBSD=	/usr/lib
SYSLIBPATH.SunOS=	/usr/lib
SYSLIBPATH=		${SYSLIBPATH.${OPSYS}}

# Nail down the directories in which headers and libraries of
# locally-installed software may be found.
#
LOCLIBPATH=		${LOCALBASE}/lib
LOCINCPATH=		${LOCALBASE}/include

# On a.out platforms, we link with "ld" and on ELF platforms, we link with
# "cc", so we need to use different options to pass the run-time search path
# flags to the link command in the right way.
#
.if ${OBJECT_FMT} == "a.out"
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/${LINKER_RPATH_FLAG} /g}
.elif ${OBJECT_FMT} == "ELF"
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/${COMPILER_RPATH_FLAG}/g}
.else
LOCLIBRPATHFLAGS=	# empty
.endif

.include "../../mk/dlopen.buildlink3.mk"

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

# By default, build with threads only if the threads are native.
.if !empty(USE_BUILTIN.pthread:M[yY][eE][sS])
PERL5_BUILD_THREADS_SUPPORT=	yes
.else
PERL5_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

### [Sat Dec 18 17:29:44 EST 2004 : jlam]
### Native threading on VAX isn't ready for primetime in NetBSD>=2.0.
### Build Perl without threads-support until VAX native threads are
### known to work.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-vax) && \
    !empty(USE_BUILTIN.pthread:M[yY][eE][sS])
PKG_HACKS+=			broken-vax-pthreads
PERL5_BUILD_THREADS_SUPPORT=	no
.endif

PKG_OPTIONS_VAR=		PKG_OPTIONS.perl
PKG_SUPPORTED_OPTIONS=		threads
.if !empty(PERL5_BUILD_THREADS_SUPPORT:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS=		threads
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	-Duseithreads
CFLAGS+=		${PTHREAD_CFLAGS}
LIBSWANTED+=		${PTHREAD_LIBS:M-l*:S/^-l//}
.else
CONFIGURE_ARGS+=	-Uuseithreads
.endif

.if !empty(LIBSWANTED)
CONFIGURE_ARGS+=	-Dlibswanted=${LIBSWANTED:Q}
.endif

.include "../../mk/compiler.mk"

.if ${OPSYS} == "IRIX"
.  if ${ABI} == "64"
CONFIGURE_ARGS+=	-Dcc=${CC:Q}" -64" -Duse64bitint
.  else
CONFIGURE_ARGS+=	-Dcc=${CC:Q}" -n32"
.  endif
.endif

# Some platforms may want the directory mode not to be 0755.  This
# is, unfortunately, hardcoded in quite a few places in Perl, so
# let's substitute what pkgsrc says instead.
#
SUBST_CLASSES+=		dirmode
SUBST_STAGE.dirmode=	post-patch
SUBST_FILES.dirmode=	installhtml installman installperl		\
			lib/ExtUtils/Install.pm
SUBST_SED.dirmode=	-e "s/755/${PKGDIRMODE}/g;/umask(/d"

# It's tough to guess which hints file will be used, so add our modifications
# to all of them:
#
# - Add the pkgsrc-derived LDFLAGS for linking against pthreads to the
#   usethreads.cbu call-back script.
#
# - Generate a pkgsrc.cbu call-back script that sets the correct LDFLAGS
#   for linking against pkgsrc-installed libraries.
#
# - Explicitly set the local compiler search paths to contain only the
#   pkgsrc-controlled directories.
#
pre-configure:
.if defined(PTHREAD_LDFLAGS) && !empty(PTHREAD_LDFLAGS)
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		{ ${ECHO} "";						\
		  ${ECHO} "cat >> UU/usethreads.cbu <<'EOCBU'";		\
		  ${ECHO} "";						\
		  ${ECHO} "# Add pkgsrc-derived ldflags to link with thread support."; \
		  ${ECHO} 'ldflags="'${PTHREAD_LDFLAGS:Q}' $$ldflags"';	\
		  ${ECHO} 'lddlflags="'${PTHREAD_LDFLAGS:Q}' $$lddlflags"'; \
		  ${ECHO} "EOCBU";					\
		} >> $${hints};						\
	done
.endif
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		{ ${ECHO} "";						\
		  ${ECHO} "cat > UU/pkgsrc.cbu <<'EOCBU'";		\
		  ${ECHO} "# This script UU/pkgsrc.cbu will get 'called-back' by Configure to set"; \
		  ${ECHO} '# linker options after all other call-back scripts have been invoked.'; \
		  ${ECHO} 'ldflags="'${LOCLIBRPATHFLAGS:Q}' $$ldflags"'; \
		  ${ECHO} 'lddlflags="'${LOCLIBRPATHFLAGS:Q}' $$lddlflags"'; \
		  ${ECHO} "EOCBU";					\
		} >> $${hints};						\
	done
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		{ ${ECHO} "";						\
		  ${ECHO} "# Set pkgsrc defaults for library and header search paths."; \
		  ${ECHO} 'locincpth="'${LOCINCPATH:Q}'"';		\
		  ${ECHO} 'loclibpth="'${LOCLIBPATH:Q}'"';		\
		} >> $${hints};						\
	done
.if !empty(SYSLIBPATH)
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		${ECHO} 'glibpth="'${SYSLIBPATH:Q}'"' >> $${hints};	\
	done
.endif

INSTALLATION_DIRS=	bin man/man1
PERL5_PACKLIST_DIR_cmd=	eval `${PERL5} -V:installarchlib 2>/dev/null`;	\
			echo $$installarchlib
PERL5_PACKLIST_DIR=	${PERL5_PACKLIST_DIR_cmd:sh}
PERL5_PACKLIST=		.packlist
FILES_SUBST+=		PERL5_COMMENT=\#
FILES_SUBST+=		PERL5_PACKLIST=
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/perllink.in		\
		> ${WRKDIR}/perllink

post-install: perl5-post-install

perl5-post-install:
	if ${TEST} -x ${PREFIX}/bin/a2p; then				\
		strip ${PREFIX}/bin/a2p;				\
	fi
	eval `${PERL5} -V:installsitearch 2>/dev/null`;			\
	eval `${PERL5} -V:installvendorarch 2>/dev/null`;		\
	${RMDIR} -p $$installsitearch 2>/dev/null || ${TRUE};		\
	${RMDIR} -p $$installvendorarch 2>/dev/null || ${TRUE};		\
	eval `${PERL5} -V:scriptdir 2>/dev/null`;			\
	eval `${PERL5} -V:man1dir 2>/dev/null`;				\
	${INSTALL_SCRIPT} ${WRKDIR}/perllink $$scriptdir/perllink;	\
	${INSTALL_MAN} ${FILESDIR}/perllink.1 $$man1dir/perllink.1;	\
	${RM} -f ${PREFIX}/bin/perllink ${PREFIX}/man/man1/perllink.1;	\
	${LN} -s $$scriptdir/perllink ${PREFIX}/bin/perllink;		\
	${LN} -s $$man1dir/perllink.1 ${PREFIX}/man/man1/perllink.1;	\
	{ ${CAT} ${PKGDIR}/PLIST;					\
	  ${ECHO} "$$scriptdir/perllink";				\
	  ${ECHO} "$$man1dir/perllink.1";				\
	} | ${SED} -e "s,^"${PREFIX:Q}"/,," > ${PLIST_SRC}

.include "packlist.mk"
.include "../../mk/bsd.pkg.mk"
