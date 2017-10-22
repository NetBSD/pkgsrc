# $NetBSD: Makefile,v 1.3 2017/10/22 20:36:31 adam Exp $

DISTNAME=	execnet-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/execnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codespeak.net/execnet
COMMENT=	Rapid multi-Python deployment
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-apipkg>=1.4:../../devel/py-apipkg
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
