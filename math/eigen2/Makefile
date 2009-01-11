# $NetBSD: Makefile,v 1.3 2009/01/11 11:45:11 markd Exp $

DISTNAME=	eigen-2.0-beta5
PKGNAME=	${DISTNAME:S/-beta/beta/}
PKGREVISION=	2
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
