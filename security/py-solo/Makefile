# $NetBSD: Makefile,v 1.2 2020/12/14 09:26:36 jperkin Exp $

GITHUB_PROJECT=	solo-python
GITHUB_TAG=	0.0.26
DISTNAME=	0.0.26
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:C/-python$//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=solokeys/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/solokeys/solo-python/
COMMENT=	Tool for managing SoloKeys
LICENSE=	apache-2.0 OR mit

WRKSRC=		${WRKDIR}/solo-python-0.0.26
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-flit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit>=0:../../devel/py-flit
TOOL_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip

DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-fido2>=0.8:../../security/py-fido2
DEPENDS+=	${PYPKGPREFIX}-intelhex>=0:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-serial>=0:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-usb>=0:../../devel/py-usb

MAKE_ENV+=	FLIT_NO_NETWORK=1

MAKE_ENV+=	PIP_DISABLE_PIP_VERSION_CHECK=1
MAKE_ENV+=	PIP_ISOLATED=1
MAKE_ENV+=	PIP_NO_CACHE_DIR=1
MAKE_ENV+=	PIP_NO_DEPS=1
MAKE_ENV+=	PIP_NO_INDEX=1
MAKE_ENV+=	PIP_PREFIX=${PREFIX:Q}
MAKE_ENV+=	PIP_PROXY=0.0.0.0:0
MAKE_ENV+=	PIP_ROOT=${DESTDIR:Q}

do-build:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m flit build

do-install:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m pip install -I \
		--no-warn-script-location \
		dist/solo_python-${PKGVERSION_NOREV}-py3-none-any.whl
	${RUN} cd ${DESTDIR:Q}${PREFIX:Q}/bin && \
	${MV} -f solo solo${PYVERSSUFFIX}

# No automatic tests here, it seems.
do-test:;

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
