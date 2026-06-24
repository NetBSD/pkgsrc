# $NetBSD: Makefile,v 1.57 2026/06/24 21:40:50 wiz Exp $

DISTNAME=	gspell-1.14.3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gspell/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/gspell
COMMENT=	Spell checking API for GTK+ applications
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

MESON_ARGS+=		-Dgtk_doc=false

PKGCONFIG_OVERRIDE+=		output/meson-private/gspell-1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

PLIST_VARS=	gir

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
USE_LANGUAGES+=		objc
# introspection fails
#CONFIGURE_ARGS+=	--disable-introspection
# Some .c files contain objective-c code.
CPPFLAGS+=		-x objective-c
# tests do not link
#SUBST_CLASSES+=         tests
#SUBST_STAGE.tests=      pre-configure
#SUBST_MESSAGE.tests=    Disabling tests.
#SUBST_FILES.tests=      Makefile.in
#SUBST_SED.tests=        -e 's,tests testsuite,,'
.else
TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.gir=		yes
.endif

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
