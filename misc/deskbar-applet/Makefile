# $NetBSD: Makefile,v 1.87 2014/05/09 07:37:11 wiz Exp $

DISTNAME=	deskbar-applet-2.32.0
PKGREVISION=	34
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/deskbar-applet/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://raphael.slinckx.net/deskbar/
COMMENT=	Omnipresent, versatile search interface for the GNOME Desktop
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE=	data/deskbar-applet.pc.in

GCONF_SCHEMAS=		deskbar-applet.schemas

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-ORBit via py-gnome2, py-gtk2

REPLACE_PYTHON=		deskbar/deskbar-applet.py
PY_PATCHPLIST=			yes

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
