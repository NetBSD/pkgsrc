# $NetBSD: Makefile,v 1.4 2019/04/26 12:44:43 roy Exp $

DISTNAME=	flufl.i18n-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.i18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/flufl.i18n/
COMMENT=	High level API for Python internationalization
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic

PYTHON_VERSIONS_ACCEPTED=	37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
