# $NetBSD: Makefile,v 1.34.2.1 2012/10/03 12:07:15 spz Exp $
#

DISTNAME=	libgweather-2.30.3
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgweather/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Weather information access library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

GCONF_SCHEMAS+=	gweather.schemas
PKGCONFIG_OVERRIDE+=	libgweather/gweather.pc.in

CONFLICTS+=	gnome-applets<2.22.0

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
