# $NetBSD: Makefile,v 1.8 2012/10/31 11:19:30 asau Exp $

.include "../../devel/fann-devel/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}.${FANNDATE}
PKGREVISION=	1

COMMENT=		Fast Artificial Neural Network python interface

USE_LANGUAGES=		c c++

PYSETUPSUBDIR=		python

EGG_NAME=		pyfann-2.0.0

.include "../../devel/fann-devel/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
