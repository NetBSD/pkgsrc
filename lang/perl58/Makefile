# $NetBSD: Makefile,v 1.44 2004/04/26 04:42:12 jlam Exp $

# The following two variables should have empty values unless we're
# building a perl snapshot or release candidate.
#
PERL5_SNAPSHOT=	# empty
PERL5_RC_VERS=	# empty

.if empty(PERL5_SNAPSHOT) && empty(PERL5_RC_VERS)
DISTNAME=	perl-${PERL5_VERS}
PKGNAME=	perl${PERL5_PKGSUFFIX}-${PERL5_VERS}
PKGREVISION=	# empty
SNAPSHOT_SITES=	# empty
.else
.  if !empty(PERL5_SNAPSHOT)
DISTNAME=	perl@${PERL5_SNAPSHOT}
PKGNAME=	perl${PERL5_PKGSUFFIX}-${PERL5_VERS}beta${PERL5_SNAPSHOT}
SNAPSHOT_SITES=	http://www.iki.fi/jhi/
EXTRACT_SUFX=	.tbz
WRKSRC=		${WRKDIR}/perl
.  else # !empty(PERL5_RC_VERS)
DISTNAME=	perl-${PERL5_VERS}-RC${PERL5_RC_VERS}
PKGNAME=	perl${PERL5_PKGSUFFIX}-${PERL5_VERS}rc${PERL5_RC_VERS}
SNAPSHOT_SITES=	http://www.cpan.org/authors/id/J/JH/JHI/
.  endif
.endif

PERL5_VERS=	5.8.4
CATEGORIES=	lang devel perl5
MASTER_SITES=	${SNAPSHOT_SITES} \
		${MASTER_SITE_PERL_CPAN:S,/modules/by-module/$,/src/,}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.perl.com/
COMMENT=	Practical Extraction and Report Language

CONFLICTS=	perl-5.00* perl-base-[0-9]* \
		p5-CGI-2.66 p5-CGI-2.75 p5-CGI-2.75.[0-2] \
		p5-Data-Dumper-2.1[0-9][0-9] p5-Data-Dumper-[0-9][0-9] \
		p5-Devel-DProf-[0-9]* p5-Devel-Peek-[0-9]* \
		perl-mk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDING_PERL5=		yes
PERL5_CONFIGURE=	no

USE_BUILDLINK3=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Dprefix="${PREFIX}"
CONFIGURE_ARGS+=	-Dscriptdir="${PREFIX}/bin"
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
CONFIGURE_ARGS+=	-Dinstallstyle="lib/perl5"
CONFIGURE_ARGS+=	-Ui_malloc
CONFIGURE_ARGS+=	-Uusemymalloc
CONFIGURE_ARGS+=	-Uinstallusrbinperl
TEST_TARGET=		test

# Install Perl man3 pages into a private directory under the the normal
# Perl installation.  Also install site-specific Perl man3 pages into a
# private directory within site_perl.  This avoids manpage conflicts
# between 3rd-party modules, the standard Perl library, and other
# packages.
#
CONFIGURE_ARGS+=	-Dman3ext="3"
CONFIGURE_ARGS+=	-Dman3dir="${PERL5_PRIVLIB}/man/man3"
CONFIGURE_ARGS+=	-Dsiteman3dir="${PERL5_SITEPERL}/man/man3"

# Ensure that the Perl man1 pages go into ${PREFIX}/man/man1 and not
# into some other platform-specific location kindly "guessed" by the
# Configure script.
#
CONFIGURE_ARGS+=	-Dman1dir="${PREFIX}/man/man1"

# The site directories are all relative to the perl view.
CONFIGURE_ARGS+=	-Dsiteprefix="${VIEWBASE}"
CONFIGURE_ARGS+=	-Dsiteman1dir="${VIEWBASE}/man/man1"

.include "../../mk/bsd.prefs.mk"

# If perl58 is built with threads support, then name the package
# "perl-thread", otherwise it's just "perl" as usual.
#
PERL5_USE_THREADS?=	no
.if !empty(PERL5_USE_THREADS:M[nN][oO])
PERL5_PKGSUFFIX=	# empty
CONFLICTS+=		perl-thread-[0-9]*
CONFIGURE_ARGS+=	-Uuseithreads
.else
PERL5_PKGSUFFIX=	-thread
CONFLICTS+=		perl-[0-9]*
CONFIGURE_ARGS+=	-Duseithreads
.  include "../../mk/pthread.buildlink3.mk"
.endif

MKPIC?=		yes

.if ${OPSYS} == "IRIX" && defined(USE_MIPSPRO)
.  if ${ABI} == "32"
PERL5_CC=		${CC:T} -n32
.  elif ${ABI} == "64"
PERL5_CC=		${CC:T} -64
CONFIGURE_ARGS+=	-Duse64bitint
.  endif
.else
PERL5_CC=		${CC:T}
.endif
CONFIGURE_ARGS+=	-Dcc="${PERL5_CC}"
MAKE_ENV+=		LANG=""

.if ${OPSYS} == "Interix"
#
# On Interix, the shared perl is actually faster, so default to that.
#
STATIC_PERL?=	no

.elif ${OPSYS} == "Darwin"
#
# The perl build attempts to work around case-insensitivity problems on
# HFS filesystems by using GNUmakefiles, so we need to use GNU make.
#
USE_GNU_TOOLS+=	make
#
# Perl is _always_ built using shared libraries on Darwin; there's no
# way to build a statically-linked perl binary.
#
MKPIC=		yes
STATIC_PERL=	no
#
# "installarchlib" and "installsitearch" have different forms between
# Darwin and NetBSD (and between older and newer versions of Darwin)
#
.if ${OS_VERSION:R} >= 7
PERL5_ARCHLIB=	${PREFIX}/lib/perl5/${PERL5_VERS}/darwin-2level
PERL5_SITEARCH=	${PREFIX}/lib/perl5/site_perl/${PERL5_VERS}/darwin-2level
.else
PERL5_ARCHLIB=	${PREFIX}/lib/perl5/${PERL5_VERS}/darwin
PERL5_SITEARCH=	${PREFIX}/lib/perl5/site_perl/${PERL5_VERS}/darwin
.endif
.endif

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.Darwin=	m c
LIBSWANTED.FreeBSD=	m crypt
LIBSWANTED.IRIX=	m crypt
LIBSWANTED.NetBSD=	m crypt
LIBSWANTED.SunOS=	m crypt dl socket nsl

# Nail down the directories in which the system libraries may be found.
# If this isn't defined, then use the perl defaults for the particular
# operating system.
#
SYSLIBPATH.Darwin=	/usr/lib
SYSLIBPATH.NetBSD=	/usr/lib
SYSLIBPATH.SunOS=	/usr/lib

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
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/${RPATH_FLAG}/g}
.elif ${OBJECT_FMT} == "ELF"
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/-Wl,${RPATH_FLAG}/g}
.else
LOCLIBRPATHFLAGS=	# empty
.endif
FIX_RPATH+=		LOCLIBRPATHFLAGS

.if defined(LIBSWANTED.${OPSYS})
CONFIGURE_ARGS+=	-Dlibswanted="${LIBSWANTED.${OPSYS}}"
.endif

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
MKPIC=		no
.  endif
.endif

.include "../../mk/compiler.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
.  if !empty(CC_VERSION:Mgcc*)
.    if !defined(_GCC_IS_TOO_OLD)
_GCC_IS_TOO_OLD!=	\
	if ${PKG_ADMIN} pmatch 'gcc<3.3' ${CC_VERSION}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
MAKEFLAGS+=	_GCC_IS_TOO_OLD=${_GCC_IS_TOO_OLD}
.    endif
.    if !empty(_GCC_IS_TOO_OLD:M[yY][eE][sS])
#
# Fix brokenness when using an older toolchain (gcc<3.3) on sparc64.
# Passing -g to the configure process triggers -DDEBUGGING, which plays
# the real trick and circumvents some code-generation bugs, so we add
# -g to CFLAGS to at least have a really debuggable build.
#
CFLAGS+=	-g -msoft-quad-float -O2
.    endif
.  endif
.endif

.if ${MKPIC} == "yes"
CONFIGURE_ARGS+=	-Duseshrplib
.endif

PERL5=			${PREFIX}/bin/perl${PERL5_VERS}
PERL5_PRIVLIB?=		${PREFIX}/lib/perl5/${PERL5_VERS}
PERL5_ARCHLIB?=		${PREFIX}/lib/perl5/${PERL5_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_SITEPERL?=	${VIEWBASE}/lib/perl5/site_perl
PERL5_SITELIB?=		${VIEWBASE}/lib/perl5/site_perl/${PERL5_VERS}
PERL5_SITEARCH?=	${VIEWBASE}/lib/perl5/site_perl/${PERL5_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_PACKLIST=		${PERL5_ARCHLIB}/.packlist
PLIST_SUBST+=		PERL5_SITEPERL=${PERL5_SITEPERL:S/^${PREFIX}\///}
MESSAGE_SUBST+=		PERL5_SITELIB=${PERL5_SITELIB}

# Some platforms may want the directory mode not to be 0755.  This is,
# unfortunately, hardcoded in quite a few places in Perl.  So let's substitute
# what pkgsrc said instead.
post-patch:
.if ${PKGDIRMODE} != "755"
.  for f in installhtml installman installperl lib/ExtUtils/Install.pm
	cd ${WRKSRC} && \
		${MV} -f $f $f.dirmode && \
		${SED} -e 's/755/${PKGDIRMODE}/g;/umask(/d' \
		$f.dirmode >$f
.  endfor
.endif

# It's tough to guess which hints file will be used, so add our modifications
# to all of them:
#
# - Explicitly set the local compiler search paths to contain only the
#   pkgsrc-controlled directories.
#
pre-configure:
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		( ${ECHO} '';						\
		  ${ECHO} 'locincpth="${LOCINCPATH}"';			\
		  ${ECHO} 'loclibpth="${LOCLIBPATH}"';			\
		  ${ECHO} 'ldflags="${LOCLIBRPATHFLAGS} $$ldflags"';	\
		) >> $${hints};						\
	done
.if defined(SYSLIBPATH.${OPSYS})
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		( ${ECHO} "glibpth='${SYSLIBPATH.${OPSYS}}'";		\
		) >> $${hints};						\
	done
.endif

# By default, on platforms that build shared libraries, rebuild the perl
# binary as a statically-linked binary as a speed optimization.  Performance
# increase is only by word-of-mouth -- no actual benchmarks have been
# produced.  However, it has been remarked that the advantage of having a
# statically-linked perl is pretty much non-existent on any platform with
# any reasonable number of registers.  These platforms should be added to
# the list below to bypass the build of the statically-linked perl.
#
.if ${MKPIC} == "yes"
.  for _arch_ in mipsel mipseb
.    if !empty(MACHINE_ARCH:M${_arch_})
STATIC_PERL?=		no
.    endif
.  endfor
.endif
STATIC_PERL?=		yes

WRKSRC_PERL5=		${WRKSRC}/perl

.if defined(STATIC_PERL) && !empty(STATIC_PERL:M[yY][eE][sS])
STATIC_WRKDIR=		${WRKDIR}/static
STATIC_MAKEFLAGS=	MKPIC=no STATIC_PERL=no
STATIC_MAKEFLAGS+=	WRKDIR=${STATIC_WRKDIR}
STATIC_MAKEFLAGS+=	ALL_TARGET=perl
WRKSRC_PERL5=		${STATIC_WRKDIR}/${WRKSRC:T}/perl
UNLIMIT_RESOURCES=      datasize

post-build:
	cd ${.CURDIR} && ${MAKE} build ${STATIC_MAKEFLAGS}
.endif

post-install:
	${RM} -f ${PREFIX}/bin/perl ${PREFIX}/bin/perl${PERL5_VERS}
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC_PERL5} ${PREFIX}/bin/perl${PERL5_VERS}
	${LN} -f ${PREFIX}/bin/perl${PERL5_VERS} ${PREFIX}/bin/perl
.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL)
	if [ -x ${PREFIX}/bin/a2p ]; then				\
		strip ${PREFIX}/bin/a2p;				\
	fi
.endif
	${RMDIR} -p ${PERL5_SITEARCH} 2>/dev/null || ${TRUE}
	${RM} -f ${WRKDIR}/bsd.perl.mk
	eval `${PERL5} -V:installsitelib 2>/dev/null` && \
		echo PERL5_SITELIB=$$installsitelib >>${WRKDIR}/bsd.perl.mk
	eval `${PERL5} -V:installsitearch 2>/dev/null` && \
		echo PERL5_SITEARCH=$$installsitearch >>${WRKDIR}/bsd.perl.mk
	eval `${PERL5} -V:installarchlib 2>/dev/null` && \
		echo PERL5_ARCHLIB=$$installarchlib >>${WRKDIR}/bsd.perl.mk
	${INSTALL_DATA_DIR} ${PREFIX}/share/mk
	${INSTALL_DATA} ${WRKDIR}/bsd.perl.mk ${PREFIX}/share/mk/bsd.perl.mk

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
