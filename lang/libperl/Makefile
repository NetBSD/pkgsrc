# $NetBSD: Makefile,v 1.16 2001/05/12 16:15:44 wiz Exp $

DISTNAME=		perl-${PERL_VERSION}
PKGNAME=		libperl-${PERL_VERSION}nb2
PERL_VERSION=		5.6.0
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		PERL core library and DynaLoader as a shared object

USE_PERL5=		# defined
PERL_REQD=		${PERL_VERSION}nb1

DISTINFO_FILE=		${.CURDIR}/../../lang/perl5-base/distinfo
PATCHDIR=		${.CURDIR}/../../lang/perl5-base/patches

HAS_CONFIGURE=		# defined
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} -Doptimize="${CFLAGS}" \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS} \
			-Dcc=gcc -Dusemymalloc=false
CONFIGURE_ARGS+=	-Duseshrplib=true
MAKE_ENV+=              LD_LIBRARY_PATH=${WRKSRC}
ALL_TARGET=		lib/Config.pm libperl.so

DYNALOADER_SRCDIR=	${WRKSRC}/ext/DynaLoader

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
IGNORE=			${PKGNAME} needs shared objects
.endif
.endif

post-build:
	cd ${DYNALOADER_SRCDIR} &&					\
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL &&		\
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} DynaLoader.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/libperl.so				\
		${PERL5_ARCHLIB}/CORE/libperl.so
	${INSTALL_DATA} ${DYNALOADER_SRCDIR}/DynaLoader.o		\
		${PERL5_ARCHLIB}/DynaLoader_pic.o

.include "../../mk/bsd.pkg.mk"
