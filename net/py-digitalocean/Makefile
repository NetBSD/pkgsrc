# $NetBSD: Makefile,v 1.3 2020/09/29 18:43:47 adam Exp $

DISTNAME=	python-digitalocean-1.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-digitalocean/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/koalalorenzo/python-digitalocean
COMMENT=	Python module to manage Digital Ocean droplets
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-jsonpickle-[0-9]*:../../textproc/py-jsonpickle
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
