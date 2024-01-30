# $NetBSD: Makefile,v 1.3 2024/01/30 14:21:55 ryoon Exp $

DISTNAME=	julius-1.7.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bvschaik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/bvschaik/julius
COMMENT=	Engine for the classic city building game Caesar III
LICENSE=	gnu-agpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

DEPENDS+=	dialog-[0-9]*:../../misc/dialog

LDFLAGS.NetBSD+=	-lexecinfo

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
