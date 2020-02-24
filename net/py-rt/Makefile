# $NetBSD: Makefile,v 1.6 2020/02/24 14:38:25 leot Exp $

DISTNAME=	rt-2.0.0
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

# Only for Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
