# $NetBSD: Makefile,v 1.2 2022/11/06 13:31:01 gdt Exp $

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

PYTHON_VERSIONS_ACCEPTED=	38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
