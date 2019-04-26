# $NetBSD: Makefile,v 1.18 2019/04/26 14:12:33 maya Exp $

DISTNAME=	ckanclient-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ckanclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ckan.org/
COMMENT=	Open-source data portal software
LICENSE=	mit

USE_LANGUAGES=	# none
REPLACE_PYTHON=	ckanclient/datastore.py
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.10

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
