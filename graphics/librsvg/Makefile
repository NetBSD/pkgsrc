# $NetBSD: Makefile,v 1.2 2001/06/11 06:34:37 jlam Exp $
#

DISTNAME=		librsvg-1.0.0
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/librsvg/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/svg/
COMMENT=		Raph's SVG library

DEPENDS+=		gnome-core>1.4.0:../../x11/gnome-core
DEPENDS+=		freetype2>=2.0.1:../../graphics/freetype2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
