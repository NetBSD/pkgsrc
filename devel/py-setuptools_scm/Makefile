# $NetBSD: Makefile,v 1.1 2015/07/20 10:42:59 wiz Exp $

DISTNAME=		setuptools_scm-1.5.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		https://pypi.python.org/packages/source/s/setuptools_scm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/setuptools_scm
COMMENT=		Manage your versions by scm tags
LICENSE=		mit

#DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

#PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
#PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
