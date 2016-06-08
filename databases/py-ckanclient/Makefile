# $NetBSD: Makefile,v 1.12 2016/06/08 17:43:21 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.10

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
