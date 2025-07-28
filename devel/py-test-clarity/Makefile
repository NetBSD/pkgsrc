# $NetBSD: Makefile,v 1.1 2025/07/28 20:36:36 dkazankov Exp $

DISTNAME=	pytest-clarity-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-clarity/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/darrenburns/pytest-clarity
COMMENT=	Pytest plugin providing an alternative, colourful diff output for failing assertions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

#DEPENDS+=	${PYPKGPREFIX}-ward-[0-9]*:../../devel/py-ward
DEPENDS+=	${PYPKGPREFIX}-test>=3.5.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-rich>=8.0.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-pprintpp>=0.4.0:../../devel/py-pprintpp

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
