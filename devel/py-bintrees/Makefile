# $NetBSD: Makefile,v 1.4 2020/10/08 21:46:26 khorben Exp $

DISTNAME=	bintrees-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bintrees/}
EXTRACT_SUFX=	.zip

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pypi.org/project/bintrees/
COMMENT=	Provides Binary-, RedBlack- and AVL-Trees in Python and Cython
LICENSE=	modified-bsd

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
