# $NetBSD: Makefile,v 1.6 2012/09/15 10:04:05 obache Exp $
#

DISTNAME=	at-spi2-core-2.5.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-core/2.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface Core
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	atspi-2.pc.in

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

BUILD_DEFS+=	VARBASE PKG_SYSCONFBASE

EGDIR=		${PREFIX}/share/examples/at-spi2-core
PKG_SYSCONFSUBDIR= at-spi2
busconfigdir=	${PKG_SYSCONFDIR}
eg_busconfigdir=	${EGDIR}/at-spi2
default_sessiondir= ${PKG_SYSCONFBASE}/xdg/autostart
eg_default_sessiondir= ${EGDIR}/xdg/autostart

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES=	${eg_busconfigdir}/accessibility.conf \
			${busconfigdir}/accessibility.conf \
		${eg_default_sessiondir}/at-spi-dbus-bus.desktop \
			${default_sessiondir}/at-spi-dbus-bus.desktop

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
