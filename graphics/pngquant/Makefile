# $NetBSD: Makefile,v 1.15 2023/05/23 06:42:08 wiz Exp $

DISTNAME=	pngquant-3.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=kornelski/}
# does not contain the git submodules, please update GITHUB_SUBMODULES below
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pngquant.org/
COMMENT=	Command-line utility for lossy compression of PNG images
LICENSE=	gnu-gpl-v3

GITHUB_SUBMODULES=	ImageOptim libimagequant 9f15d1c lib
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.lcms2}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/pngquant.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
