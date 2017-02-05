# $NetBSD: Makefile,v 1.8 2017/02/05 19:11:41 wiz Exp $

DISTNAME=	mccabe-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mccabe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/mccabe/
COMMENT=	Mccabe plugin for the Python program checker flake8
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} > 30
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
