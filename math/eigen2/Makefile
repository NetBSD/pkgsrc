# $NetBSD: Makefile,v 1.4 2009/01/27 12:22:46 markd Exp $

DISTNAME=	eigen-2.0-beta6
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	math
MASTER_SITES=   http://download.tuxfamily.org/eigen/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra

USE_LANGUAGES+= c c++
USE_CMAKE= yes

WRKSRC=		${WRKDIR}/eigen2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
