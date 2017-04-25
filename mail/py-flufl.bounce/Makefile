# $NetBSD: Makefile,v 1.1 2017/04/25 20:17:03 fhajny Exp $

DISTNAME=	flufl.bounce-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.bounce/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.bounce/
COMMENT=	Email bounce detectors
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	36 35 34

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose2-[0-9]*:../../devel/py-nose2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
