# $NetBSD: Makefile,v 1.47 2024/10/20 14:02:23 wiz Exp $

DISTNAME=	at-spi2-core-2.54.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-core/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface Core
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt pkg-config

SUPERSEDES+=	at-spi2-atk2-[0-9]*
SUPERSEDES+=	atk-[0-9]*
CONFLICTS+=	at-spi2-atk2-[0-9]*
CONFLICTS+=	atk-[0-9]*

BUILD_DEFS+=		PKG_SYSCONFDIR

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

SUBST_CLASSES+=		eg
SUBST_SED.eg+=		-e 's,defaults,examples/${PKGBASE},'
SUBST_FILES.eg+=	bus/meson.build
SUBST_STAGE.eg=		pre-configure
SUBST_MESSAGE.eg=	Fixing path to examples directory.

CONF_FILES=	${EGDIR}/at-spi2/accessibility.conf \
		${PKG_SYSCONFDIR}/at-spi2/accessibility.conf
CONF_FILES+=	${EGDIR}/xdg/autostart/at-spi-dbus-bus.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/at-spi-dbus-bus.desktop
MAKE_DIRS+=	${PKG_SYSCONFDIR}/at-spi2
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/xdg/autostart
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/autostart/at-spi-dbus-bus.desktop \
	      ${DESTDIR}${EGDIR}/xdg/autostart/at-spi-dbus-bus.desktop

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
