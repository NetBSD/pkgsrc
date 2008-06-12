# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:28 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

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
