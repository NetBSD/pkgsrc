# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:11 wiz Exp $

DISTNAME=	ijson-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ijson/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/ICRAR/ijson
COMMENT=	Iterative JSON parser with standard Python iterator interfaces
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/yajl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
