# $NetBSD: Makefile,v 1.9 2026/08/05 02:30:44 adam Exp $

DISTNAME=	flufl_bounce-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.bounce/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fluflbounce.readthedocs.io/en/latest/
COMMENT=	Email bounce detectors
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
TEST_DEPENDS+=	${PYPKGPREFIX}-sybil>=0:../../devel/py-sybil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
