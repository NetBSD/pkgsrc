# $NetBSD: Makefile,v 1.1 2026/04/15 08:05:37 adam Exp $

DISTNAME=	audioop_lts-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/audioop-lts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AbstractUmbra/audioop
COMMENT=	LTS Port of Python audioop
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 312

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
