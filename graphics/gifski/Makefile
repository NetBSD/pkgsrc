# $NetBSD: Makefile,v 1.1 2023/01/12 12:55:46 pin Exp $

DISTNAME=	gifski-1.8.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ImageOptim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ImageOptim/gifski/
COMMENT=	GIF encoder based on libimagequant (pngquant)
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gifski \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
