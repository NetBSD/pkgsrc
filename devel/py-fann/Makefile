# $NetBSD: Makefile,v 1.5 2006/10/12 19:05:08 gdt Exp $

.include "../../devel/fann-devel/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}.${FANNDATE}

COMMENT=		Fast Artificial Neural Network python interface

USE_LANGUAGES=		c c++

PYDISTUTILSPKG=		YES
PYSETUPSUBDIR=		python

.include "../../devel/fann-devel/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
