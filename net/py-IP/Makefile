# $NetBSD: Makefile,v 1.25 2022/01/10 08:40:59 wiz Exp $

DISTNAME=	IPy-1.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IPy/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/haypo/python-ipy
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

EGG_NAME=	IPy-1.1

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_IPy.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
