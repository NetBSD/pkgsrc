# $NetBSD: Makefile,v 1.2 2008/04/16 16:45:23 drochner Exp $
#

DISTNAME=	libgweather-2.22.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgweather/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Weather information access library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

GCONF_SCHEMAS+=	gweather.schemas
PKGCONFIG_OVERRIDE+=	libgweather/gweather.pc.in

CONFLICTS+=	gnome-applets<2.22.0

.include "../../devel/GConf/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
