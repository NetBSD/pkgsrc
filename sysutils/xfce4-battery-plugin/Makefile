# $NetBSD: Makefile,v 1.1.1.1 2007/04/27 10:48:06 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.0

DISTNAME=	xfce4-battery-plugin-${XFCE4_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-battery-plugin/
COMMENT=	Xfce battey monitor plugin

USE_TOOLS+=	perl:run

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
