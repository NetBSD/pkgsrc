# $NetBSD: Makefile,v 1.20 2003/09/17 19:40:43 grant Exp $

PERL5_SNAPSHOT=	# empty
PERL5_VERS=	5.8.0

.if empty(PERL5_SNAPSHOT)
DISTNAME=	perl-${PERL5_VERS}
SNAPSHOT_SITES=	# empty
.else
DISTNAME=	perl@${PERL5_SNAPSHOT}
PKGNAME=	perl-${PERL5_VERS}
SNAPSHOT_SITES=	http://www.iki.fi/jhi/
.endif

PKGREVISION=	2
CATEGORIES=	lang devel perl5
MASTER_SITES=	${SNAPSHOT_SITES} \
		ftp://ftp.funet.fi/pub/languages/perl/CPAN/src/ \
		ftp://ftp.ruhr-uni-bochum.de/mirrors/ftp.funet.fi/pub/languages/perl/CPAN/src/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.perl.com/
COMMENT=	Practical Extraction and Report Language

CONFLICTS=	perl-5.00* perl-base-[0-9]* \
		p5-CGI-2.66 p5-CGI-2.75 p5-CGI-2.75.[0-2] \
		p5-Data-Dumper-2.1[0-9][0-9] p5-Data-Dumper-[0-9][0-9] \
		p5-Devel-DProf-[0-9]* p5-Devel-Peek-[0-9]* \
		perl-mk-[0-9]*

USE_BUILDLINK2=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Dprefix="${PREFIX}"
CONFIGURE_ARGS+=	-Dscriptdir="${PREFIX}/bin"
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
CONFIGURE_ARGS+=	-Dcc="${CC:T}"
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
CONFIGURE_ARGS+=	-Dinstallsiteman3dir="${PERL5_SITEPERL}/man/man3"

.include "../../mk/bsd.prefs.mk"

MKPIC?=		yes

.if ${OPSYS} == "Darwin"
#
# The perl build attempts to work around case-insensitivity problems on
# HFS filesystems by using GNUmakefiles, so we need to use GNU make.
#
USE_GMAKE=	YES
#
# Perl is _always_ built using shared libraries on Darwin; there's no
# way to build a statically-linked perl binary.
#
MKPIC=		yes
STATIC_PERL=	NO
#
# "installarchlib" and "installsitearch" have different forms between
# Darwin and NetBSD.
#
PERL5_ARCHLIB=	${PREFIX}/lib/perl5/${PERL5_VERS}/${LOWER_OPSYS}
PERL5_SITEARCH=	${PREFIX}/lib/perl5/site_perl/${PERL5_VERS}/${LOWER_OPSYS}
.endif

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.Darwin=	m c
LIBSWANTED.FreeBSD=	m crypt
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
MKPIC=			no
.  endif
.  if ${MACHINE_ARCH} == "sparc64"
# The toolchain on sparc64 is not really production-quality right now, but
# gcc-2.96 is supposed to fix most problems.  Passing -g to the configure
# process triggers -DDEBUGGING, which plays the real trick and circumvents
# code-generation bugs, so we add -g to CFLAGS to at least have a really
# debuggable build.
#
CFLAGS+=		-g -msoft-quad-float -O2
.  endif
.elif ${OPSYS} == "SunOS"
CFLAGS=
.endif

.if ${MKPIC} == "yes"
CONFIGURE_ARGS+=	-Duseshrplib
.endif

PERL5=			${PREFIX}/bin/perl${PERL5_VERS}
PERL5_PRIVLIB?=		${PREFIX}/lib/perl5/${PERL5_VERS}
PERL5_ARCHLIB?=		${PREFIX}/lib/perl5/${PERL5_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_SITEPERL?=	${PREFIX}/lib/perl5/site_perl
PERL5_SITEARCH?=	${PREFIX}/lib/perl5/site_perl/${PERL5_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_PACKLIST=		${PERL5_ARCHLIB}/.packlist
PLIST_SUBST+=		PERL5_SITEPERL=${PERL5_SITEPERL:S/^${PREFIX}\///}

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
STATIC_PERL?=		NO
.    endif
.  endfor
.endif
STATIC_PERL?=		YES

.if defined(STATIC_PERL) && ${STATIC_PERL} == "YES"
STATIC_WRKDIR=		${WRKDIR}/static
STATIC_MAKEFLAGS=	MKPIC=no STATIC_PERL=NO
STATIC_MAKEFLAGS+=	WRKDIR=${STATIC_WRKDIR}
STATIC_MAKEFLAGS+=	ALL_TARGET=perl

post-build:
	cd ${.CURDIR} && ${MAKE} build ${STATIC_MAKEFLAGS}
.endif

post-install:
.if defined(STATIC_PERL) && ${STATIC_PERL} == "YES"
	${RM} -f ${PERL5}
	${INSTALL_PROGRAM} ${STATIC_WRKDIR}/${WRKSRC:T}/perl ${PERL5}
.endif
	${RM} -f ${PREFIX}/bin/perl
	${LN} -f ${PERL5} ${PREFIX}/bin/perl
	strip ${PERL5}
	if [ -x ${PREFIX}/bin/a2p ]; then				\
		strip ${PREFIX}/bin/a2p;				\
	fi
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

.if ${MACHINE_ARCH} == "alpha"
USE_PKGSRC_GCC=		# defined
.endif

.include "../../mk/bsd.pkg.mk"
