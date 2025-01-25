# $NetBSD: Makefile,v 1.56 2025/01/25 10:15:23 riastradh Exp $

DISTNAME=	at-spi2-core-2.54.0
PKGREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-core/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface Core
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt pkg-config

SUPERSEDES+=	at-spi2-atk-[0-9]*
SUPERSEDES+=	atk-[0-9]*
CONFLICTS+=	at-spi2-atk-[0-9]*
CONFLICTS+=	atk-[0-9]*

BUILD_DEFS+=		PKG_SYSCONFDIR

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

SUBST_CLASSES+=		eg
SUBST_SED.eg+=		-e 's,defaults,examples/${PKGBASE},'
SUBST_FILES.eg+=	bus/meson.build
SUBST_STAGE.eg=		pre-configure
SUBST_MESSAGE.eg=	Fixing path to examples directory.

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
TOOL_DEPENDS+=			glib2-tools>=0:../../devel/glib2-tools
MESON_BINARIES+=		glib-genmarshal glib-mkenums
MESON_BINARY.glib-genmarshal=	${TOOLBASE}/bin/glib-genmarshal
MESON_BINARY.glib-mkenums=	${TOOLBASE}/bin/glib-mkenums
.endif

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
