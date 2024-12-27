# $NetBSD: Makefile,v 1.19 2024/12/27 20:57:14 adam Exp $

DISTNAME=	python_socks-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-socks/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/python-socks
COMMENT=	Core proxy (SOCKS4, SOCKS5, HTTP tunneling) functionality for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
# asyncio
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0:../../devel/py-async-timeout
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
