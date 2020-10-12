# $NetBSD: Makefile,v 1.3 2020/10/12 21:51:57 bacon Exp $

DISTNAME=	Ipopt-3.11.5
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Ipopt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://projects.coin-or.org/Ipopt
COMMENT=	Interior Point OPTimizer

USE_LANGUAGES=	c c++03 fortran
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

TEST_TARGET=	test

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
