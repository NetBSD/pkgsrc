# $NetBSD: Makefile,v 1.7 2016/10/19 13:55:53 wiz Exp $

DISTNAME=	setuptools_scm-1.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
# https://github.com/pypa/setuptools_scm/issues/114
EGG_NAME=	setuptools_scm-1.14.1.dev0+ng7961046.d20161012

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
