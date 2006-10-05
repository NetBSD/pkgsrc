# $NetBSD: Makefile,v 1.4 2006/10/05 18:51:01 gdt Exp $

.include "../../devel/fann/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}
PKGREVISION=	1

COMMENT=		Fast Artificial Neural Network python interface

PYDISTUTILSPKG=		YES
PYSETUPSUBDIR=		python

.include "../../devel/fann/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
