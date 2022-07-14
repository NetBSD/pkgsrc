# $NetBSD: Makefile,v 1.16 2022/07/14 23:46:23 dholland Exp $

DISTNAME=	lcms2-2.12
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcms/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Little Color Management System - a color management library
LICENSE=	mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	lcms2.pc.in
TEST_TARGET=		check

# lcms does not need zlib, but will look for it and link it to tifficc
# if present.  Therefore, we don't enjoin lcms from finding zlib, but
# don't include it via bl3.

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
