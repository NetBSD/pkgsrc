# $NetBSD: Makefile,v 1.23 2012/09/07 19:17:34 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.0

DISTNAME=	xfce4-cpugraph-plugin-${XFCE4_VERSION}
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-cpugraph-plugin/
COMMENT=	Xfce CPU load plugin

USE_TOOLS+=	autoconf

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
