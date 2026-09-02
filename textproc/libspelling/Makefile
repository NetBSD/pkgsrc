# $NetBSD: Makefile,v 1.2 2026/09/02 19:04:44 wiz Exp $

DISTNAME=	libspelling-0.4.10
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libspelling/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libspelling
COMMENT=	Spellcheck library for GTK 4
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-gi-docgen-[0-9]*:../../devel/py-gi-docgen
TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dsysprof=false

PKGCONFIG_OVERRIDE+=		output/meson-private/libspelling-1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../lang/python/pyversion.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
