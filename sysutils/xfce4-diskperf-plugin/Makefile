# $NetBSD: Makefile,v 1.14 2007/04/17 18:20:06 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.0

DISTNAME=	xfce4-diskperf-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-diskperf-plugin/
COMMENT=	Xfce disk performance plugin

NOT_FOR_PLATFORM+=	DragonFly-*-*

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
