# $NetBSD: Makefile,v 1.4 2024/01/20 16:04:03 wiz Exp $

DISTNAME=	py-tlsh-4.7.2
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-tlsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/py-tlsh/
COMMENT=	TLSH C++ extension for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/tlsh/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
