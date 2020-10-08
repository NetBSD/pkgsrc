# $NetBSD: Makefile,v 1.3 2020/10/08 17:13:12 khorben Exp $

DISTNAME=	bintrees-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bintrees/}
EXTRACT_SUFX=	.zip

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pypi.org/project/bintrees/
COMMENT=	Provides Binary-, RedBlack- and AVL-Trees in Python and Cython
LICENSE=	modified-bsd

USE_LANGUAGES=	c

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

PYTHON_VERSIONS_ACCEPTED=	37 36

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
