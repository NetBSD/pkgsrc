# $NetBSD: Makefile,v 1.4 2021/02/09 07:24:38 adam Exp $

DISTNAME=	python-digitalocean-1.16.0
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
