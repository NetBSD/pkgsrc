# $NetBSD: Makefile,v 1.12 2013/12/08 13:46:44 prlw1 Exp $

DISTNAME=	at-spi2-atk-2.10.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-atk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface A11y Toolkit
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	atk-bridge-2.0.pc.in

BUILDLINK_API_DEPENDS.atk+=	atk>=2.9.4
.include "../../devel/atk/buildlink3.mk"
BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.9.4
.include "../../devel/at-spi2-core/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
