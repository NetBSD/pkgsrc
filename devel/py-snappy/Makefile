# $NetBSD: Makefile,v 1.2 2023/10/29 18:28:57 wiz Exp $

DISTNAME=	python-snappy-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-snappy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andrix/python-snappy
COMMENT=	Python library for the snappy compression library from Google
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.15.0:../../devel/py-cffi

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
