# $NetBSD: Makefile,v 1.49 2009/03/16 12:37:22 jmcneill Exp $

DISTNAME=	eel-2.26.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eel/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Eazel Extensions Library for GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	eel-2.0.pc.in

CONFLICTS+=		eel2-[0-9]*

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.15.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.9.4
BUILDLINK_API_DEPENDS.gnome-desktop+=	gnome-desktop>=2.25.5

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
