# $NetBSD: Makefile,v 1.4 2010/06/13 22:44:38 wiz Exp $

DISTNAME=	libpano13-2.9.14
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=panotools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://panotools.sourceforge.net/
COMMENT=	Cross-platform library behind Panorama Tools and other stitchers

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
