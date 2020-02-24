# $NetBSD: Makefile,v 1.5 2020/02/24 13:38:38 leot Exp $

DISTNAME=	rt-1.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rt/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/CZ-NIC/python-rt
COMMENT=	Python interface to Request Tracker API
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	py-rt	# XXX: avoid possible conflicts with devel/rt{3,}

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
