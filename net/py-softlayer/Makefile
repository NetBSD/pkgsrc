# $NetBSD: Makefile,v 1.18 2023/10/14 17:21:49 adam Exp $

DISTNAME=	SoftLayer-6.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SoftLayer/softlayer/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoftLayer/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/softlayer/softlayer-python
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=8.0.4:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-prettytable>=2.5.0:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rich>=13.5.3:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in sl slcli
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
