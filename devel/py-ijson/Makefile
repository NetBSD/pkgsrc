# $NetBSD: Makefile,v 1.8 2025/05/19 09:12:35 adam Exp $

DISTNAME=	ijson-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ijson/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/ICRAR/ijson
COMMENT=	Iterative JSON parser with standard Python iterator interfaces
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../devel/yajl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
