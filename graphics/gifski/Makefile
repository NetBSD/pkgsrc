# $NetBSD: Makefile,v 1.8 2023/09/25 08:28:57 wiz Exp $

DISTNAME=	gifski-1.11.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ImageOptim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ImageOptim/gifski/
COMMENT=	GIF encoder based on libimagequant (pngquant)
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gifski \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
