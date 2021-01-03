# $NetBSD: Makefile,v 1.24 2021/01/03 21:52:16 adam Exp $

DISTNAME=	IPy-1.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IPy/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/haypo/python-ipy
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_IPy.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
