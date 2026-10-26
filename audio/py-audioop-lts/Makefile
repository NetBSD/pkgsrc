# $NetBSD: Makefile,v 1.3 2026/10/26 06:06:13 wiz Exp $

DISTNAME=	audioop_lts-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/audioop-lts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AbstractUmbra/audioop
COMMENT=	LTS Port of Python audioop
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	311 312

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
