# $NetBSD: Makefile,v 1.8 2026/10/26 20:36:13 ktnb Exp $

DISTNAME=	py_tlsh-4.12.1
PKGNAME=	${DISTNAME:S/py_/${PYPKGPREFIX}-/:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-tlsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/py-tlsh/
COMMENT=	TLSH C++ extension for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

WRKSRC=	${WRKDIR}/${DISTNAME:S/_/-/}

.include "../../devel/tlsh/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
