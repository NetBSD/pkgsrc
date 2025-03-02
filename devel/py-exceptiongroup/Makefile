# $NetBSD: Makefile,v 1.15 2025/03/02 09:01:43 wiz Exp $

DISTNAME=	exceptiongroup-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/exceptiongroup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/exceptiongroup
COMMENT=	Backport of PEP 654 (exception groups)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_scm-[0-9]*:../../devel/py-flit_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
