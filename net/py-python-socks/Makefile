# $NetBSD: Makefile,v 1.29 2026/10/16 18:19:33 adam Exp $

DISTNAME=	python_socks-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-socks/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/python-socks
COMMENT=	Core proxy (SOCKS4, SOCKS5, HTTP tunneling) functionality for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-anyio>=4.12.1:../../devel/py-anyio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.2.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=1.2.1:../../security/py-trustme

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
