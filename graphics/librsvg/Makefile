# $NetBSD: Makefile,v 1.9 2003/05/02 11:55:24 wiz Exp $
#

DISTNAME=		librsvg-1.0.1
PKGREVISION=	3
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/librsvg/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/svg/
COMMENT=		Raph's SVG library

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
