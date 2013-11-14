# $NetBSD: Makefile,v 1.1.1.1 2013/11/14 15:04:12 asau Exp $

DISTNAME=	Ipopt-3.11.5
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Ipopt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://projects.coin-or.org/Ipopt
COMMENT=	Interior Point OPTimizer

USE_LANGUAGES=	c c++ fortran
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

TEST_TARGET=	test

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
