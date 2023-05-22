# $NetBSD: Makefile,v 1.30 2023/05/22 11:37:14 wiz Exp $

DISTNAME=	libimagequant-4.2.0
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	High-quality conversion of RGBA images to 8-bit indexed-color
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	cargo-c>=0.9.19:../../devel/cargo-c

WRKSRC=		${WRKDIR}/${DISTNAME}/imagequant-sys

PKGCONFIG_OVERRIDE=		${DESTDIR}${PREFIX}/lib/pkgconfig/imagequant.pc
PKGCONFIG_OVERRIDE_STAGE=	post-install

.include "cargo-depends.mk"

do-install:
	cd ${WRKSRC} && ${RUN} cargo cinstall --destdir=${DESTDIR} --prefix=${PREFIX} --libdir=${PREFIX}/lib

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
