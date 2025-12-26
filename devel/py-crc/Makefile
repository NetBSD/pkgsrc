# $NetBSD: Makefile,v 1.2 2025/12/26 14:11:42 wiz Exp $

DISTNAME=	crc-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crc/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/Nicoretti/crc
COMMENT=	Pure Python CRC library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} crc crc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
