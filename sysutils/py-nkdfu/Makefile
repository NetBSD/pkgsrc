# $NetBSD: Makefile,v 1.1 2023/05/18 12:39:49 nikita Exp $

DISTNAME=	nkdfu-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nkdfu/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://pypi.org/project/nkdfu/
COMMENT=	Python DFU tool for updating Nitrokeys' firmware
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-libusb1-[0-9]*:../../devel/py-libusb1
DEPENDS+=	${PYPKGPREFIX}-intelhex-[0-9]*:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-fire-[0-9]*:../../devel/py-fire

# Only supports python 3.6 or higher.
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

#FIXME
#REPLACE_PYTHON+=	nkdfu/dfu_flash.py

SUBST_CLASSES+=         python
SUBST_STAGE.python=     pre-build
SUBST_MESSAGE.python=   Fix python invocation
SUBST_FILES.python+=    nkdfu/dfu_flash.py
SUBST_SED.python+=      -e 's,/usr/bin/env.*,${PYTHONBIN},g'


post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/nkdfu ${DESTDIR}${PREFIX}/bin/nkdfu-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
