# $NetBSD: Makefile,v 1.4 2022/01/05 15:41:10 wiz Exp $

DISTNAME=	pyevmasm-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=crytic/}
GITHUB_PROJECT=	pyevmasm
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/trailofbits/pyevmasm
COMMENT=	Ethereum Virtual Machine (EVM) assembler and disassembler
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/evmasm \
		${DESTDIR}${PREFIX}/bin/evmasm-${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
