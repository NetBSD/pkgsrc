# $NetBSD: Makefile,v 1.57 2020/11/05 09:07:31 ryoon Exp $

PKGREVISION= 18
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-xmms-plugin-0.5.3
CATEGORIES=	audio
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-xmms-plugin/0.5/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-xmms-plugin
COMMENT=	Xfce XMMS plugin

.include "../../audio/bmp/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
