# $NetBSD: Makefile,v 1.1.1.1 2002/10/16 10:29:01 rh Exp $
#

DISTNAME=		librsvg-2.0.1
PKGNAME=		${DISTNAME:S/-/2-/}
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/librsvg/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.levien.com/svg/
COMMENT=		SVG library for GNOME2

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
