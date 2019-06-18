# $NetBSD: Makefile,v 1.40 2019/06/18 05:54:02 wiz Exp $

DISTNAME=	Mnemosyne-2.3.1
PKGNAME=	${DISTNAME:S/M/m/}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mnemosyne-proj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mnemosyne-proj.org/
COMMENT=	Sophisticated flash-card tool which optimizes your learning process
LICENSE=	gnu-gpl-v2

BROKEN=		MatPlotLib requires Python 3.x and newer Mnemosyne requires qt5-qtwebengine.

#DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-sip-[0-9]*:../../x11/py-sip
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-static-[0-9]*:../../www/py-static
DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 2.3.1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
