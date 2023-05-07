# $NetBSD: Makefile,v 1.28 2023/05/07 12:24:08 wiz Exp $

DISTNAME=	libimagequant-4.2.0
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	High-quality conversion of RGBA images to 8-bit indexed-color
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/imagequant-sys

.include "cargo-depends.mk"

INSTALLATION_DIRS=	include lib/pkg-config

post-build:
	cd ${WRKSRC} && \
        ${SED} 's|@PREFIX@|${PREFIX}|;s|@VERSION@|${VERSION}|' < imagequant.pc.in > imagequant.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/libimagequant.h \
		${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/imagequant.pc \
		${DESTDIR}${PREFIX}/lib/pkg-config
	${INSTALL_LIB} ${WRKSRC}/../target/release/libimagequant_sys.a \
		${DESTDIR}${PREFIX}/lib/libimagequant.a

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
