# $NetBSD: Makefile,v 1.10 2017/12/27 23:32:37 he Exp $

DISTNAME=	cx_Freeze-5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_F/f/}
PKGREVISION=	1
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
