# $NetBSD: Makefile,v 1.15 2025/10/09 08:01:57 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	claripy-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/claripy/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/claripy
COMMENT=	Abstraction layer for constraint solvers
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-z3>=4.13.0.0:../../math/py-z3

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
