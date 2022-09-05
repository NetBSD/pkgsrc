# $NetBSD: Makefile,v 1.1 2022/09/05 14:12:15 adam Exp $

DISTNAME=	pkgutil_resolve_name-1.3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkgutil_resolve_name/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/graingert/pkgutil-resolve-name
COMMENT=	Resolve a name to an object
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	38 37

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
