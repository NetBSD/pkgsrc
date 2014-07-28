# $NetBSD: Makefile,v 1.20 2014/07/28 02:38:24 wen Exp $

DISTNAME=	IPy-0.81
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/I/IPy/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/haypo/python-ipy/
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

do-test:
	${RUN}cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_IPy.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
