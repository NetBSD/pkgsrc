# $NetBSD: Makefile,v 1.16 2026/04/15 08:10:07 adam Exp $

DISTNAME=	audioread-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/audioread/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/audioread
COMMENT=	Audio file decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} >= 313
DEPENDS+=	${PYPKGPREFIX}-standard-aifc>=3.13:../../audio/py-standard-aifc
DEPENDS+=	${PYPKGPREFIX}-standard-sunau>=3.13:../../audio/py-standard-sunau
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
