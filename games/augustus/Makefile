# $NetBSD: Makefile,v 1.3 2023/11/03 17:25:03 triaxx Exp $

DISTNAME=	augustus-3.2.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Keriew/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/Keriew/augustus
COMMENT=	Enhanced engine for the classic city building game Caesar III
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
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
