# $NetBSD: Makefile,v 1.18 2020/12/20 15:15:01 fcambus Exp $

DISTNAME=		ucon64-2.2.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ucon64/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ucon64.sourceforge.io/
COMMENT=		Emulator ROM and disk image converter and inspector
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/src

CONFIGURE_ARGS+=		--with-libcd64
CONFIGURE_ARGS+=		--with-libdiscmage
GNU_CONFIGURE=			yes
USE_TOOLS+=			gmake
CHECK_PORTABILITY_SKIP+=	install_beos.sh

INSTALLATION_DIRS=	bin lib share/examples/ucon64 share/doc/ucon64/images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucon64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libdiscmage/discmage.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/[a-z]*.txt \
		${DESTDIR}${PREFIX}/share/examples/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.html \
		${DESTDIR}${PREFIX}/share/doc/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/images/* \
		${DESTDIR}${PREFIX}/share/doc/ucon64/images

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
