# $NetBSD: Makefile,v 1.1 2021/02/17 15:21:34 ryoon Exp $

DISTNAME=	fcitx5-gtk-5.0.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-gtk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-gtk
COMMENT=	GTK input method module for fcitx5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DENABLE_GTK4_IM_MODULE=off

PKGCONFIG_OVERRIDE+=	fcitx-gclient/Fcitx5GClient.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
