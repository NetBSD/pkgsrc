# $NetBSD: Makefile,v 1.10 2021/06/10 07:33:32 adam Exp $

DISTNAME=	SoftLayer-5.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SoftLayer/softlayer/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoftLayer/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/softlayer/softlayer-python
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-ptable>=0.9.2:../../textproc/py-ptable
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sl sl-${PYVERSSUFFIX} && \
	${MV} slcli slcli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
