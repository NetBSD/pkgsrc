# $NetBSD: Makefile,v 1.23 2006/07/19 19:14:38 jlam Exp $

DISTNAME=	librsvg-1.0.3
PKGREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.levien.com/svg/
COMMENT=	Raph's SVG library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
