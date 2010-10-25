# $NetBSD: Makefile,v 1.7 2010/10/25 20:03:52 markd Exp $

DISTNAME=	2.0.15
PKGNAME=	eigen-2.0.15
CATEGORIES=	math
MASTER_SITES=   http://bitbucket.org/eigen/eigen/get/
DIST_SUBDIR=	eigen2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2

USE_LANGUAGES+= c c++
USE_CMAKE= yes
WRKSRC=		${WRKDIR}/eigen

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
