# $NetBSD: Makefile,v 1.19 2025/11/17 11:01:02 wiz Exp $

DISTNAME=	cx_Freeze-6.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cx_Freeze/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://cx-freeze.sourceforge.net/
COMMENT=	Freezing python scripts into executables
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	27

PLIST_SUBST+=	PYVERNODOT=${PYVERSSUFFIX:S/.//g}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv cxfreeze cxfreeze-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && mv cxfreeze-quickstart cxfreeze-quickstart-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
