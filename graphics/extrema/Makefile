# $NetBSD: Makefile,v 1.22 2013/06/06 12:54:29 wiz Exp $
#

DISTNAME=	extrema-4.4.4
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=extrema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://exsitewebware.com/extrema/
COMMENT=	Visualization and data analysis tool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CONFIGURE_ARGS+=	--with-wxGTK

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
