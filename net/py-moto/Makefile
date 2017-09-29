# $NetBSD: Makefile,v 1.1 2017/09/29 21:31:20 joerg Exp $

DISTNAME=	moto-1.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spulec/moto
COMMENT=	Mock-up of the boto library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-boto>=2.36.0:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.2.1:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.8:../../textproc/py-jinja2

# Tests
BUILD_DEPENDS+=	${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm
BUILD_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
BUILD_DEPENDS+=	${PYPKGPREFIX}-sure-[0-9]*:../../devel/py-sure
BUILD_DEPENDS+=	${PYPKGPREFIX}-dicttoxml-[0-9]*:../../textproc/py-dicttoxml
BUILD_DEPENDS+=	${PYPKGPREFIX}-pyaml-[0-9]*:../../textproc/py-pyaml
BUILD_DEPENDS+=	${PYPKGPREFIX}-cookies-[0-9]*:../../www/py-cookies
BUILD_DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

do-test:
	# Bad test case in version 1.1.10
	rm -f ${WRKSRC}/tests/test_cloudformation/test_server.py
	set -e; for t in ${WRKSRC}/tests/test*; do cd $$t; \
	    PYTHONPATH=${WRKSRC} py.test-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
