# $NetBSD: Makefile,v 1.6 2012/09/13 17:34:22 asau Exp $

DISTNAME=	mpc-1.0.1
PKGNAME=	mpcomplex-1.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/mpc/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.multiprecision.org/mpc/
COMMENT=	Multiprecision complex arithmetic library
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

# The test that checks version match between binary library and
# headers MIGHT NEED THE PACKAGE INSTALLED. Might fail otherwise.
TEST_TARGET=	check

BUILDLINK_API_DEPENDS.gmp+=	gmp>=4.3.2
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.4.2
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
