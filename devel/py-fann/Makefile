# $NetBSD: Makefile,v 1.2 2006/10/05 15:00:42 gdt Exp $

.include "../../devel/fann/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}

COMMENT=		Fast Artificial Neural Network python interface

PYDISTUTILSPKG=		YES
PYSETUPSUBDIR=		python

.include "../../devel/fann/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
