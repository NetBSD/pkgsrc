# $NetBSD: Makefile,v 1.44 2008/11/26 08:21:36 jnemeth Exp $

DISTNAME=	eel-2.24.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eel/2.24/}
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

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.6.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.9.4
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.23.0
BUILDLINK_API_DEPENDS.gnome-desktop+=	gnome-desktop>=2.23.3

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
