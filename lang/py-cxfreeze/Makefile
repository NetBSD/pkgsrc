# $NetBSD: Makefile,v 1.13 2020/03/20 11:57:56 nia Exp $

DISTNAME=	cx_Freeze-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cx_Freeze/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://cx-freeze.sourceforge.net/
COMMENT=	Freezing python scripts into executables
LICENSE=	python-software-foundation

REPLACE_PYTHON=	cx_Freeze/samples/PyQt5/PyQt5app.py

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}
	${MV} ${WRKSRC}/cxfreeze-quickstart ${WRKSRC}/cxfreeze-quickstart${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
