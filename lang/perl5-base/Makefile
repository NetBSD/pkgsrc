# $NetBSD: Makefile,v 1.7 2001/06/07 04:25:34 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		perl-base-${PERL5_VERS}
PERL5_PKG_VERS=		# empty
CATEGORIES+=		lang devel

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		base installation of Perl

CONFLICTS=		perl-5.00* p5-CGI-2.6* p5-CGI-2.7[0-5]

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Dprefix="${PREFIX}"
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
CONFIGURE_ARGS+=	-Dcc="${CC}"
CONFIGURE_ARGS+=	-Uusemymalloc
CONFIGURE_ARGS+=	-Uinstallusrbinperl

.include "../../mk/bsd.prefs.mk"

MKPIC?=			yes

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.
#
LIBSWANTED.NetBSD=	m crypt

.if defined(LIBSWANTED.${OPSYS})
CONFIGURE_ARGS+=	-Dlibswanted="${LIBSWANTED.${OPSYS}}"
.endif

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
MKPIC=			no
.endif
.if ${MACHINE_ARCH} == "sparc64"
# The toolchain on sparc64 is not really production-quality right now, but
# gcc-2.96 is supposed to fix most problems.  Passing -g to the configure
# process triggers -DDEBUGGING, which plays the real trick and circumvents
# code-generation bugs, so we add -g to CFLAGS to at least have a really
# debuggable build.
#
CFLAGS+=		-g -msoft-quad-float -O2
.endif
.elif ${OPSYS} == "SunOS"
CFLAGS=
.endif

.if ${MKPIC} == "yes"
CONFIGURE_ARGS+=	-Duseshrplib
.endif

PERL5_ARCHLIB=		${PREFIX}/lib/perl5/${PERL5_DIST_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_SITEARCH=		${PREFIX}/lib/perl5/site_perl/${PERL5_DIST_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_PACKLIST=		${PERL5_ARCHLIB}/.packlist

# Remove modules that are externally available in pkgsrc and that also install
# manpages.
#
pre-configure:
	cd ${WRKSRC}; ${RM} -rf eg/cgi lib/CGI lib/CGI.pm

.if ${MKPIC} == "yes"
#
# Build a static libperl.a and relink perl against it as a runtime
# optimization.
#
post-configure:
	${CAT} Makefile.static >> ${WRKSRC}/${MAKEFILE}

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} libperl.a
	@${RM} -f ${WRKSRC}/perl
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} perl	\
		LLIBPERL=libperl.a
.endif

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl
	${RMDIR} -p ${PERL5_SITEARCH} 2>/dev/null || ${TRUE}

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} test

.include "../../mk/bsd.pkg.mk"
