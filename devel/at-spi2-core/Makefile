# $NetBSD: Makefile,v 1.14 2013/12/08 13:40:20 prlw1 Exp $

DISTNAME=	at-spi2-core-2.10.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-core/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface Core
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

PKGCONFIG_OVERRIDE+=	atspi-2.pc.in

BUILD_DEFS+=	VARBASE PKG_SYSCONFBASE

EGDIR=			${PREFIX}/share/examples/at-spi2-core
PKG_SYSCONFSUBDIR=	at-spi2
busconfigdir=		${PKG_SYSCONFDIR}
eg_busconfigdir=	${EGDIR}/at-spi2
default_sessiondir=	${PKG_SYSCONFBASE}/xdg/autostart
eg_default_sessiondir=	${EGDIR}/xdg/autostart

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES=	${eg_busconfigdir}/accessibility.conf \
			${busconfigdir}/accessibility.conf
CONF_FILES+=	${eg_default_sessiondir}/at-spi-dbus-bus.desktop \
			${default_sessiondir}/at-spi-dbus-bus.desktop
MAKE_DIRS+=	${default_sessiondir}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
