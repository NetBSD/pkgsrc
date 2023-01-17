# $NetBSD: Makefile,v 1.7 2023/01/17 09:08:18 adam Exp $

DISTNAME=	python-socks-2.1.1
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
