# $NetBSD: Makefile,v 1.9 2023/09/25 09:42:34 pin Exp $

DISTNAME=	gifski-1.12.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ImageOptim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ImageOptim/gifski/
COMMENT=	GIF encoder based on libimagequant (pngquant)
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
