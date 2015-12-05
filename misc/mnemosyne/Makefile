# $NetBSD: Makefile,v 1.31 2015/12/05 21:25:50 adam Exp $

DISTNAME=	Mnemosyne-2.3.1
PKGNAME=	${DISTNAME:S/M/m/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mnemosyne-proj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mnemosyne-proj.org/
COMMENT=	Sophisticated flash-card tool which optimizes your learning process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-sip-[0-9]*:../../x11/py-sip
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-static-[0-9]*:../../www/py-static
DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 2.3.1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
