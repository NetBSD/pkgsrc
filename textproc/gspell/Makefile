# $NetBSD: Makefile,v 1.59 2026/09/02 19:04:42 wiz Exp $

DISTNAME=	gspell-1.14.4
PKGREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gspell/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/gspell
COMMENT=	Spell checking API for GTK+ applications
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

MESON_ARGS+=	-Dgtk_doc=false
MESON_ARGS+=	-Dinstall_tests=false # fail on Darwin

PKGCONFIG_OVERRIDE+=		output/meson-private/gspell-1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
