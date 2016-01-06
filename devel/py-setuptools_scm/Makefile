# $NetBSD: Makefile,v 1.3 2016/01/06 05:30:56 wiz Exp $

DISTNAME=		setuptools_scm-1.10.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=s/setuptools_scm/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/setuptools_scm
COMMENT=		Manage your versions by scm tags
LICENSE=		mit

#DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

#PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
#PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
