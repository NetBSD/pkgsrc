# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:53 wiz Exp $

DISTNAME=	bitstring-3.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/bitstring
COMMENT=	Simple construction, analysis and modification of binary data
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/test && \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
