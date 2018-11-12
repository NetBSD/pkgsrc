# $NetBSD: Makefile,v 1.73 2018/11/12 03:52:35 ryoon Exp $
#

DISTNAME=	mousetweaks-2.32.1
PKGREVISION=	21
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mousetweaks/2.32/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Mousetweaks/Home
COMMENT=	Mouse accessibility software
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.3

GNU_CONFIGURE=	yes

GCONF_SCHEMAS+=	mousetweaks.schemas
GCONF_SCHEMAS+=	pointer-capture-applet.schemas

USE_TOOLS+=	gmake intltool msgfmt pkg-config

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
.include "../../devel/at-spi/buildlink3.mk"
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.4.0
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
