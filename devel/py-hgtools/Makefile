# $NetBSD: Makefile,v 1.6 2017/09/12 04:00:07 adam Exp $

DISTNAME=	hgtools-6.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hgtools/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/hgtools
COMMENT=	Classes and setuptools plugin for Mercurial and Git repositories
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
