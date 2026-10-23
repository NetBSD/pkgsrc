# $NetBSD: Makefile,v 1.5 2026/10/23 14:32:40 ktnb Exp $

DISTNAME=	py_tlsh-4.12.1
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-tlsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/py-tlsh/
COMMENT=	TLSH C++ extension for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

.include "../../devel/tlsh/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
