# $NetBSD: Makefile,v 1.7 2013/01/26 21:37:54 adam Exp $

DISTNAME=	lcms2-2.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcms/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Little Color Management System -- a color management library
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

# lcms does not need zlib, but will look for it and link it to tifficc
# if present.  Therefore, we don't enjoin lcms from finding zlib, but
# don't include it via bl3.

PKGCONFIG_OVERRIDE=	lcms2.pc.in

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
