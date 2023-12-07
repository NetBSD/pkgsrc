# $NetBSD: Makefile,v 1.70 2023/12/07 02:14:47 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-cpugraph-plugin-1.2.10
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-cpugraph-plugin/1.2/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-cpugraph-plugin
COMMENT=	Xfce CPU load plugin

USE_LANGUAGES=	c c++

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17
FORCE_C_STD=		c99
FORCE_CXX_STD=		c++17

CXXFLAGS.SunOS+=	-fpermissive

.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.18.0
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
