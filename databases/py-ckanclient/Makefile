# $NetBSD: Makefile,v 1.13 2016/07/09 13:03:35 wiz Exp $

DISTNAME=	ckanclient-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ckanclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ckan.org/
COMMENT=	Open-source data portal software
LICENSE=	mit

USE_LANGUAGES=	# none
REPLACE_PYTHON=	ckanclient/datastore.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.10

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
