# $NetBSD: Makefile,v 1.4 2016/08/28 15:48:31 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
