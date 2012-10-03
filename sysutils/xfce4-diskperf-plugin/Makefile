# $NetBSD: Makefile,v 1.28.2.1 2012/10/03 12:09:33 spz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.0

DISTNAME=	xfce4-diskperf-plugin-${XFCE4_VERSION}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-diskperf-plugin/
COMMENT=	Xfce disk performance plugin

ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
