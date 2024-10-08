# $NetBSD: Makefile,v 1.16 2024/10/08 17:24:59 adam Exp $

DISTNAME=	python_socks-2.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-socks/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/python-socks
COMMENT=	Core proxy (SOCKS4, SOCKS5, HTTP tunneling) functionality for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
# asyncio
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=3.0.1:../../devel/py-async-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
