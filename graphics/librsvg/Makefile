# $NetBSD: Makefile,v 1.4 2002/03/13 17:37:12 fredb Exp $
#

DISTNAME=		librsvg-1.0.1
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/librsvg/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/svg/
COMMENT=		Raph's SVG library

DEPENDS+=		gnome-core>=1.4.0.4nb1:../../x11/gnome-core
DEPENDS+=		freetype2>=2.0.1:../../graphics/freetype2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
