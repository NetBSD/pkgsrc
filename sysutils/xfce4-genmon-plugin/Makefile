# $NetBSD: Makefile,v 1.15 2012/10/02 17:12:01 tron Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	3.1

DISTNAME=	xfce4-genmon-plugin-${XFCE4_VERSION}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-genmon-plugin/
COMMENT=	Xfce general purpose monitor plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
