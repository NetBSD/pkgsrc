# $NetBSD: Makefile,v 1.66.2.1 2012/10/03 12:07:02 spz Exp $
#

DISTNAME=		at-spi-1.32.0
PKGREVISION=		9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		PYTHON=true

PKGCONFIG_OVERRIDE+=	cspi-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libloginhelper-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libspi-1.0.pc.in

GCONF_SCHEMAS=		at-spi.schemas

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=1.17.0
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
