# $NetBSD: Makefile,v 1.15 2011/11/02 10:58:33 obache Exp $

DISTNAME=	IPy-0.75
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/I/IPy/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/haypo/python-ipy/
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

do-test:
	${RUN}cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_IPy.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
