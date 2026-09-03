# $NetBSD: Makefile,v 1.3 2026/09/03 11:27:25 adam Exp $

DISTNAME=	crc-8.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crc/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/Nicoretti/crc
COMMENT=	Pure Python CRC library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	crc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
