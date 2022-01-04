# $NetBSD: Makefile,v 1.15 2022/01/04 20:54:08 wiz Exp $

DISTNAME=	cx_Freeze-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cx_Freeze/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://cx-freeze.sourceforge.net/
COMMENT=	Freezing python scripts into executables
LICENSE=	python-software-foundation

REPLACE_PYTHON=	cx_Freeze/samples/PyQt5/PyQt5app.py

SUBST_CLASSES+=		pyver
SUBST_STAGE.pyver=	pre-configure
SUBST_SED.pyver+=	-e 's/"cxfreeze"/"cxfreeze'${PYVERSSUFFIX}'"/'
SUBST_SED.pyver+=	-e 's/"cxfreeze-quickstart"/"cxfreeze-quickstart'${PYVERSSUFFIX}'"/'
SUBST_FILES.pyver+=	setup.py
SUBST_MESSAGE.pyver=	Fixing path to scripts.

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}
	${MV} ${WRKSRC}/cxfreeze-quickstart ${WRKSRC}/cxfreeze-quickstart${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
