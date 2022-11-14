# $NetBSD: Makefile,v 1.7 2022/11/14 17:52:18 wiz Exp $

DISTNAME=	bintrees-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bintrees/}
EXTRACT_SUFX=	.zip

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mozman/bintrees
COMMENT=	Provides Binary-, RedBlack- and AVL-Trees in Python and Cython
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27

# 2.2.0 distfile does not support python 3.11
post-extract:
	${RM} ${WRKSRC}/bintrees/cython_trees.c
	cd ${WRKSRC} && cythonize-${PYVERSSUFFIX} bintrees

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
