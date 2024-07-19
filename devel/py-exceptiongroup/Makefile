# $NetBSD: Makefile,v 1.14 2024/07/19 08:16:29 adam Exp $

DISTNAME=	exceptiongroup-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/exceptiongroup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/exceptiongroup
COMMENT=	Backport of PEP 654 (exception groups)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_scm-[0-9]*:../../devel/py-flit_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
