# $NetBSD: Makefile,v 1.16 2026/08/05 02:35:38 adam Exp $

DISTNAME=	flufl_lock-9.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flufllock.readthedocs.io/
COMMENT=	NFS-safe file locking with timeouts for POSIX systems
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-sybil-[0-9]*:../../devel/py-sybil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
