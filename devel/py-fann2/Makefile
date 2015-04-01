# $NetBSD: Makefile,v 1.2 2015/04/01 01:53:44 rodent Exp $

DISTNAME=	fann2-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/f/fann2/

MAINTAINER=	pkgsrc@futurelinkcorporation.com
HOMEPAGE=	https://github.com/FutureLinkCorporation/fann2
COMMENT=	Python bindings for Fast Artificial Neural Network (FANN)
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	swig2-[0-9]*:../../devel/swig2

USE_LANGUAGES=	c c++

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/fann/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
