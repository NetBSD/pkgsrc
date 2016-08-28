# $NetBSD: Makefile,v 1.7 2016/08/28 15:48:32 wiz Exp $

VERS=			4.2.3
DISTNAME=		cx_Freeze-${VERS}
PKGNAME=		${PYPKGPREFIX}-cxfreeze-${VERS}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cx-freeze/}

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://cx-freeze.sourceforge.net/
COMMENT=		Freezing python scripts into executables
LICENSE=		python-software-foundation

USE_LANGUAGES=      	c c++

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
