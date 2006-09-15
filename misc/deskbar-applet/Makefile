# $NetBSD: Makefile,v 1.9 2006/09/15 15:24:32 jmmv Exp $
#

DISTNAME=	deskbar-applet-2.16.0
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/deskbar-applet/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://raphael.slinckx.net/deskbar
COMMENT=	Omnipresent, versatile search interface for the GNOME Desktop

BROKEN_IN=		pkgsrc-2006Q1

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE=	data/deskbar-applet.pc

GCONF2_SCHEMAS=		deskbar-applet.schemas

PYTHON_ACCEPTED_VERSIONS=	24
PYTHON_PATCH_SCRIPTS=		deskbar/deskbar-applet.py
PY_PATCHPLIST=			yes

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
