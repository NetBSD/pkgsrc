# $NetBSD: Makefile,v 1.12 2023/12/17 16:07:37 adam Exp $

DISTNAME=	python-socks-2.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-socks/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/python-socks
COMMENT=	Core proxy (SOCKS4, SOCKS5, HTTP tunneling) functionality for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=  ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=  ${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=3.0.1:../../devel/py-async-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
