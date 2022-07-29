# $NetBSD: Makefile,v 1.43 2022/07/29 16:29:08 jperkin Exp $

DISTNAME=	at-spi2-core-2.40.3
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-core/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface Core
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		msgfmt pkg-config

PKGCONFIG_OVERRIDE=		output/meson-private/atspi-2.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/atspi

LIBS.SunOS+=	-lintl

BUILD_DEFS+=		PKG_SYSCONFBASE

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
busconfigdir=		${PKG_SYSCONFDIR}/at-spi2
eg_busconfigdir=	${EGDIR}/at-spi2
default_sessiondir=	${PKG_SYSCONFBASE}/xdg/autostart
eg_default_sessiondir=	${EGDIR}/xdg/autostart

SUBST_CLASSES+=		eg
SUBST_SED.eg+=		-e 's,defaults,examples/${PKGBASE},'
SUBST_FILES.eg+=	bus/meson.build
SUBST_STAGE.eg=		pre-configure
SUBST_MESSAGE.eg=	Fixing path to examples directory.

CONF_FILES=	${eg_busconfigdir}/accessibility.conf \
			${busconfigdir}/accessibility.conf
CONF_FILES+=	${eg_default_sessiondir}/at-spi-dbus-bus.desktop \
			${default_sessiondir}/at-spi-dbus-bus.desktop
MAKE_DIRS+=	${busconfigdir} ${default_sessiondir}

PYTHON_FOR_BUILD_ONLY=	tool

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${eg_default_sessiondir}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/autostart/at-spi-dbus-bus.desktop \
	      ${DESTDIR}${eg_default_sessiondir}/at-spi-dbus-bus.desktop

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
