# $NetBSD: Makefile,v 1.10 2014/01/25 10:30:03 wiz Exp $

.include "../../devel/fann/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}

COMMENT=		Fast Artificial Neural Network python interface

USE_LANGUAGES=		c c++

PYSETUPSUBDIR=		python
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 2.1.0.20061012

EGG_NAME=		pyfann-${FANNVERSION}

.include "../../devel/fann/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
