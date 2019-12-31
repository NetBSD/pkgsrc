# $NetBSD: Makefile,v 1.2 2019/12/31 13:05:10 triaxx Exp $

DISTNAME=	python-digitalocean-1.14.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=koalalorenzo/}
GITHUB_PROJECT=	${DISTNAME:C/-[^-]*$//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/koalalorenzo/python-digitalocean
COMMENT=	Python module to manage Digital Ocean droplets
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-jsonpickle-[0-9]*:../../textproc/py-jsonpickle
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
