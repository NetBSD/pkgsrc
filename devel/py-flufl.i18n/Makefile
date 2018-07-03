# $NetBSD: Makefile,v 1.3 2018/07/03 05:03:11 adam Exp $

DISTNAME=	flufl.i18n-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.i18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.i18n/
COMMENT=	High level API for Python internationalization
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic

PYTHON_VERSIONS_ACCEPTED=	37 36 35 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
