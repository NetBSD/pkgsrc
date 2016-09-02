# $NetBSD: Makefile,v 1.1 2016/09/02 16:46:04 wiz Exp $

DISTNAME=	arx-libertatis-1.1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=project/arx/arx-libertatis-1.1.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arx-libertatis.org/
COMMENT=	Cross-platform, open source port of the Arx Fatalis RPG
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-D CMAKE_INSTALL_MANDIR:STRING:=${PKGMANDIR}
CMAKE_ARGS+=	-D USE_QT4:BOOL=OFF
CMAKE_ARGS+=	-D USE_QT5:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	NotDarwin

.if ${OPSYS} != "Darwin"
PLIST.NotDarwin= yes
.endif

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
