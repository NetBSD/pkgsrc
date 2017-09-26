# $NetBSD: Makefile,v 1.22 2017/09/26 17:37:40 adam Exp $

DISTNAME=	IPy-0.83
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IPy/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/haypo/python-ipy/
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_IPy.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
