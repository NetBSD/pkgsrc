# $NetBSD: Makefile,v 1.17 2023/01/29 21:16:19 ryoon Exp $

DISTNAME=	oshu-2.0.2
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fmang/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fmang/oshu
COMMENT=	Fast osu! port
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

LDFLAGS+=	-lm # fmaf()

CMAKE_ARGS+=	-DOSHU_SKINS="minimal"

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
