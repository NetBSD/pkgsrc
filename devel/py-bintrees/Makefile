# $NetBSD: Makefile,v 1.6 2022/01/04 20:52:52 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
