# $NetBSD: Makefile,v 1.3 2022/01/10 08:48:30 wiz Exp $

DISTNAME=	pyaes-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyaes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ricmoo/pyaes
COMMENT=	Pure-Python implementation of AES block-cipher
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/test-aes.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
