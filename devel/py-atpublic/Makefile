# $NetBSD: Makefile,v 1.2 2017/09/18 17:08:28 adam Exp $

DISTNAME=	atpublic-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atpublic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://public.readthedocs.io/
COMMENT=	@public decorator for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
