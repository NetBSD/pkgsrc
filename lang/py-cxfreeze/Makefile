# $NetBSD: Makefile,v 1.12 2020/01/18 23:32:45 rillig Exp $

DISTNAME=	cx_Freeze-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cx_Freeze/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://cx-freeze.sourceforge.net/
COMMENT=	Freezing python scripts into executables
LICENSE=	python-software-foundation

REPLACE_PYTHON=	cx_Freeze/samples/PyQt5/PyQt5app.py

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}
	${MV} ${WRKSRC}/cxfreeze-quickstart ${WRKSRC}/cxfreeze-quickstart${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
