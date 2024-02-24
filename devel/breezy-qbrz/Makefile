# $NetBSD: Makefile,v 1.7 2024/02/24 12:25:15 rhialto Exp $

WHEEL_NAME=	qbrz-0.5.0
DISTNAME=	breezy-qbrz-0.5.0.0.${VER}
CATEGORIES=	devel
VER=		1667	# 0.5.0+
SITES.${DISTNAME}.tar.gz= \
	-https://bazaar.launchpad.net/~qbrz/qbrz/trunk/tarball/${VER}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://launchpad.net/qbrz
COMMENT=	GUI front end for Breezy
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-fastbencode>0:../../converters/py-fastbencode
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.15:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sip6>=6:../../x11/py-sip6
DEPENDS+=	${PYPKGPREFIX}-sip-qt5>=12:../../x11/py-sip-qt5
# The following two are optional (and large).
#DEPENDS+=	${PYPKGPREFIX}-enchant>=0:../../textproc/py-enchant
#DEPENDS+=	${PYPKGPREFIX}-pygments>=0:../../textproc/py-pygments

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=	msgfmt
WRKSRC=		${WRKDIR}/~qbrz/qbrz/trunk

REPLACE_PYTHON=		lib/uifactory.py

.include "../../devel/breezy/plugin.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
