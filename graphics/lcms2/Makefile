# $NetBSD: Makefile,v 1.25 2026/04/30 13:16:04 gdt Exp $

DISTNAME=	lcms2-2.19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcms/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Little Color Management System - a color management library
LICENSE=	mit

# Upstream added cmake support in 2.19, but that has not been declared
# official/favored.  Pending upstream commentary (requested 20260430)
# or some compelling reason, the package will remain on autoconf,
# because the of the usual pattern of cmake build systems having
# regressions from autoconf in various areas, typically cross
# compilation and testing non-installed versions, at least until those
# are assessed.
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
