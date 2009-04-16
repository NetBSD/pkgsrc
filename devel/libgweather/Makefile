# $NetBSD: Makefile,v 1.13 2009/04/16 19:37:50 drochner Exp $
#

DISTNAME=	libgweather-2.26.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgweather/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Weather information access library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

GCONF_SCHEMAS+=	gweather.schemas
PKGCONFIG_OVERRIDE+=	libgweather/gweather.pc.in

CONFLICTS+=	gnome-applets<2.22.0

.include "../../devel/GConf/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
