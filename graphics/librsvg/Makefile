# $NetBSD: Makefile,v 1.5 2002/07/20 11:36:02 kent Exp $
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

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
