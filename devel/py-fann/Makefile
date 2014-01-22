# $NetBSD: Makefile,v 1.9 2014/01/22 01:44:10 gdt Exp $

.include "../../devel/fann/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}

COMMENT=		Fast Artificial Neural Network python interface

USE_LANGUAGES=		c c++

PYSETUPSUBDIR=		python

EGG_NAME=		pyfann-${FANNVERSION}

.include "../../devel/fann/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
