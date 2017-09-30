# $NetBSD: Makefile,v 1.9 2017/09/30 13:44:35 adam Exp $

DISTNAME=	cx_Freeze-5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cx_Freeze/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://cx-freeze.sourceforge.net/
COMMENT=	Freezing python scripts into executables
LICENSE=	python-software-foundation

USE_LANGUAGES=	c c++

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}
	${MV} ${WRKSRC}/cxfreeze-quickstart ${WRKSRC}/cxfreeze-quickstart${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
