# $NetBSD: Makefile,v 1.20 2025/12/22 06:08:09 adam Exp $

DISTNAME=	gifski-1.34.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ImageOptim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ImageOptim/gifski/
COMMENT=	GIF encoder based on libimagequant (pngquant)
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
