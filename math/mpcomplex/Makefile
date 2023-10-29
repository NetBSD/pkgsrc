# $NetBSD: Makefile,v 1.13 2023/10/29 18:06:59 wiz Exp $

DISTNAME=	mpc-1.3.1
PKGNAME=	${DISTNAME:S/mpc/mpcomplex/}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mpc/}

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.multiprecision.org/mpc/
COMMENT=	Multiprecision complex arithmetic library
LICENSE=	gnu-lgpl-v3

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

# The test that checks version match between binary library and
# headers MIGHT NEED THE PACKAGE INSTALLED. Might fail otherwise.
TEST_TARGET=	check

BUILDLINK_API_DEPENDS.gmp+=	gmp>=4.3.2
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=4.1.0
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
