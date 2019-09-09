# $NetBSD: Makefile,v 1.11 2019/09/09 12:05:01 maya Exp $

DISTNAME=	2.0.17
PKGNAME=	eigen-2.0.17
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://bitbucket.org/eigen/eigen/get/
DIST_SUBDIR=	eigen2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/eigen-eigen-b23437e61a07

.include "../../mk/bsd.pkg.mk"
