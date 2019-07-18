# $NetBSD: Makefile,v 1.22 2019/07/18 15:03:51 prlw1 Exp $

DISTNAME=	at-spi2-atk-2.33.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-atk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface A11y Toolkit
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	output/meson-private/atk-bridge-2.0.pc
PKGCONFIG_OVERRIDE_STAGE=pre-install

BUILDLINK_API_DEPENDS.atk+=	atk>=2.33.3
.include "../../devel/atk/buildlink3.mk"
BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.33.2
.include "../../devel/at-spi2-core/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.5
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../devel/py-meson/build.mk"
.include "../../mk/bsd.pkg.mk"
