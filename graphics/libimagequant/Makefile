# $NetBSD: Makefile,v 1.31 2023/06/06 12:41:34 riastradh Exp $

DISTNAME=	libimagequant-4.2.0
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	High-quality conversion of RGBA images to 8-bit indexed-color
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	cargo-c>=0.9.19:../../devel/cargo-c

WRKSRC=		${WRKDIR}/${DISTNAME}/imagequant-sys

PKGCONFIG_OVERRIDE=		${DESTDIR}${PREFIX}/lib/pkgconfig/imagequant.pc
PKGCONFIG_OVERRIDE_STAGE=	post-install

.include "cargo-depends.mk"

do-install:
	cd ${WRKSRC} && ${RUN} cargo cinstall --destdir=${DESTDIR} --prefix=${PREFIX} --libdir=${PREFIX}/lib

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
