# $NetBSD: Makefile,v 1.2 2023/08/06 19:11:18 adam Exp $

EGG_NAME=	qbrz-0.4.1
DISTNAME=	breezy-qbrz-0.4.1.0.${VER}
CATEGORIES=	devel
VER=		1652	# 0.4.1+
SITES.${DISTNAME}.tar.gz= \
	-https://bazaar.launchpad.net/~qbrz/qbrz/trunk/tarball/${VER}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://launchpad.net/qbrz
COMMENT=	GUI front end for Breezy
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-fastbencode>0:../../converters/py-fastbencode
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.15:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sip6>=6:../../x11/py-sip6

USE_TOOLS+=	msgfmt
WRKSRC=		${WRKDIR}/~qbrz/qbrz/trunk

REPLACE_PYTHON=		lib/uifactory.py

.include "../../devel/breezy/plugin.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
