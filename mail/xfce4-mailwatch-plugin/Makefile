# $NetBSD: Makefile,v 1.4 2017/02/06 13:55:39 wiz Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mailwatch-plugin-1.2.0
CATEGORIES=	mail
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-mailwatch-plugin/1.2/

CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/libs

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-mailwatch-plugin
COMMENT=	Xfce mail checker plugin for the panel

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
