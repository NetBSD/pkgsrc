# $NetBSD: Makefile,v 1.8 2017/02/14 09:54:30 markd Exp $

VERS=			5.0.1
DISTNAME=		cx_Freeze-${VERS}
PKGNAME=		${PYPKGPREFIX}-cxfreeze-${VERS}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_PYPI:=c/cx-freeze/}

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://cx-freeze.sourceforge.net/
COMMENT=		Freezing python scripts into executables
LICENSE=		python-software-foundation

USE_LANGUAGES=      	c c++

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}
	${MV} ${WRKSRC}/cxfreeze-quickstart ${WRKSRC}/cxfreeze-quickstart${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
