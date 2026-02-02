# $NetBSD: Makefile,v 1.5 2026/02/02 18:54:25 wiz Exp $

DISTNAME=	pytokens-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytokens/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tusharsadhwani/pytokens
COMMENT=	Fast, spec compliant Python 3.12+ tokenizer
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../lang/py-mypy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
