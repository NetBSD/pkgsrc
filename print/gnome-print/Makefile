# $NetBSD: Makefile,v 1.76 2007/01/09 13:31:02 joerg Exp $

DISTNAME=		gnome-print-0.37
PKGREVISION=		2
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-print/0.37/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gs:run msgfmt perl

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-admin		# currently unstable

# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC:Q}

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		x11path
SUBST_FILES.x11path+=	run-gnome-font-install
SUBST_SED.x11path+=	-e 's,@X11BASE@,${X11BASE},g'
SUBST_STAGE.x11path=	pre-configure

.if ${X11_TYPE} == "xorg"
BUILD_DEPENDS+=	xorg-fontsTruetype-[0-9]*:../../fonts/xorg-fontsTruetype
BUILD_DEPENDS+=	xorg-fontsType1-[0-9]*:../../fonts/xorg-fontsType1
.endif

BUILD_DEPENDS+=	ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
