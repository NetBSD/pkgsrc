# $NetBSD: Makefile,v 1.5 2023/10/28 19:57:16 wiz Exp $

DISTNAME=	nkdfu-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nkdfu/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://pypi.org/project/nkdfu/
COMMENT=	Python DFU tool for updating Nitrokeys' firmware
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-libusb1-[0-9]*:../../devel/py-libusb1
DEPENDS+=	${PYPKGPREFIX}-intelhex-[0-9]*:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-fire-[0-9]*:../../devel/py-fire

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	nkdfu/dfu_flash.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/nkdfu ${DESTDIR}${PREFIX}/bin/nkdfu-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
