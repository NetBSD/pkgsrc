# $NetBSD: Makefile,v 1.9 2000/05/16 14:46:44 veego Exp $
#

DISTNAME=		perl5.004_04
PKGNAME=		libperl-5.00404
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

USE_PERL5=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if exists(/usr/libexec/ld.elf_so)
PLIST_SRC=		${PKGDIR}/PLIST-elf
.elif exists(/usr/libexec/ld.so)
PLIST_SRC=		${PKGDIR}/PLIST-aout
.else
IGNORE=			"needs shared object support"
.endif
.elif ${OPSYS} == "SunOS"
PLIST_SRC=		${PKGDIR}/PLIST-elf
.endif
PATCHDIR=		../perl5/patches

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} -Duseshrplib=true \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS} \
			-Dusemymalloc=false
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	-Dcc="${CC}"
.endif
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}
ALL_TARGET=		perl

post-build:
	cd ${WRKSRC}/ext/DynaLoader && ${RM} DynaLoader.o && \
		${MAKE} DynaLoader.o && ${MV} DynaLoader.o DynaLoader_pic.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/libperl.so* \
		${PREFIX}/lib/perl5/${MACHINE_ARCH}-${LOWER_OPSYS}/5.00404/CORE/
	${INSTALL_PROGRAM} ${WRKSRC}/perl ${PREFIX}/bin/soperl
	${INSTALL_DATA} ${WRKSRC}/ext/DynaLoader/DynaLoader_pic.o \
		${PREFIX}/lib/perl5/${MACHINE_ARCH}-${LOWER_OPSYS}/5.00404/

.include "../../mk/bsd.pkg.mk"
