# $NetBSD: Makefile,v 1.1 2023/01/01 14:12:05 rhialto Exp $

EGG_NAME=	qbrz-0.4.1
DISTNAME=	breezy-qbrz-0.4.1.0.${VER}
CATEGORIES=	devel
VER=		1651	# 0.4.1+
SITES.${DISTNAME}.tar.gz= \
	-https://bazaar.launchpad.net/~qbrz/qbrz/trunk/tarball/${VER}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://launchpad.net/qbrz
COMMENT=	GUI front end for Breezy
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-fastbencode>0:../../converters/py-fastbencode
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.15:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sip>=4<5:../../x11/py-sip

USE_TOOLS+=	msgfmt
WRKSRC=		${WRKDIR}/~qbrz/qbrz/trunk

REPLACE_PYTHON=		lib/uifactory.py

.include "../../devel/breezy/plugin.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
