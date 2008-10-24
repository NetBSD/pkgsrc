# $NetBSD: Makefile,v 1.47 2008/10/24 19:30:32 wiz Exp $
#

DISTNAME=		at-spi-1.24.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.24/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface

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

BUILDLINK_API_DEPENDS.atk+=	atk>=1.18.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
