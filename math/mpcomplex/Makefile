# $NetBSD: Makefile,v 1.10 2018/01/28 16:24:11 wiz Exp $

DISTNAME=	mpc-1.0.3
PKGNAME=	${DISTNAME:S/mpc/mpcomplex/}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/mpc/download/
MASTER_SITES+=	${MASTER_SITE_GNU:=mpc/}

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
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.4.2
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
