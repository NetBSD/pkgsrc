# $NetBSD: Makefile,v 1.1 2025/07/28 20:53:23 dkazankov Exp $

DISTNAME=	pytest-pretty-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=samuelcolvin/}
GITHUB_PROJECT=	pytest-pretty
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/pytest-pretty
COMMENT=	Pytest plugin providing an alternative, colourful diff output for failing assertions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
