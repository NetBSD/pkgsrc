# $NetBSD: Makefile,v 1.16 2022/11/14 19:19:24 wiz Exp $

DISTNAME=	cx_Freeze-6.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cx_Freeze/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://cx-freeze.sourceforge.net/
COMMENT=	Freezing python scripts into executables
LICENSE=	python-software-foundation

REPLACE_PYTHON=	cx_Freeze/samples/PyQt5/PyQt5app.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv cxfreeze cxfreeze-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && mv cxfreeze-quickstart cxfreeze-quickstart-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
