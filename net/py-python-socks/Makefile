# $NetBSD: Makefile,v 1.6 2022/03/17 14:24:31 adam Exp $

DISTNAME=	python-socks-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-socks/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/python-socks
COMMENT=	Core proxy (SOCKS4, SOCKS5, HTTP tunneling) functionality for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=3.0.1:../../devel/py-async-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
