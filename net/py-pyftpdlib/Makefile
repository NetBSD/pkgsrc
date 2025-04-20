# $NetBSD: Makefile,v 1.12 2025/04/20 12:32:50 adam Exp $

DISTNAME=	pyftpdlib-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyftpdlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/pyftpdlib
COMMENT=	Very fast asynchronous FTP server library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-pysendfile-[0-9]*:../../net/py-pysendfile

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} >= 312
DEPENDS+=	${PYPKGPREFIX}-pyasyncore-[0-9]*:../../devel/py-pyasyncore
DEPENDS+=	${PYPKGPREFIX}-pyasynchat-[0-9]*:../../devel/py-pyasynchat
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ftpbench ftpbench-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
