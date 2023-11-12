# $NetBSD: Makefile,v 1.42 2023/11/12 13:23:41 wiz Exp $

DISTNAME=	gspell-1.8.4
PKGREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gspell/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/gspell
COMMENT=	Spell checking API for GTK+ applications
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	gspell.pc.in

PLIST_VARS=	gir

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
.include "../../x11/gtk-mac-integration/buildlink3.mk"
USE_LANGUAGES+=		objc
# introspection fails
CONFIGURE_ARGS+=	--disable-introspection
# Some .c files contain objective-c code.
CPPFLAGS+=		-x objective-c
# tests do not link
SUBST_CLASSES+=         tests
SUBST_STAGE.tests=      pre-configure
SUBST_MESSAGE.tests=    Disabling tests.
SUBST_FILES.tests=      Makefile.in
SUBST_SED.tests=        -e 's,tests testsuite,,'
.else
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.gir=		yes
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
