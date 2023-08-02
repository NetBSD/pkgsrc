# $NetBSD: Makefile,v 1.4 2023/08/02 19:21:55 nia Exp $

DISTNAME=	Ipopt-3.11.5
PKGREVISION=	1
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

# Fails with C++14 default language
FORCE_CXX_STD=	c++03

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
