# $NetBSD: Makefile,v 1.1 2025/12/25 17:00:07 ryoon Exp $

DISTNAME=	crc-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crc/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/Nicoretti/crc
COMMENT=	Pure Python CRC library
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} crc crc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
