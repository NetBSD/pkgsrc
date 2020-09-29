# $NetBSD: Makefile,v 1.3 2020/09/29 20:02:09 jperkin Exp $

DISTNAME=	wasm-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=athre0z/}
GITHUB_PROJECT=	wasm
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/athre0z/wasm
COMMENT=	WebAssembly decoder & disassembler
LICENSE=	mit

USE_LANGUAGES=	c++

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/wasmdump \
		${DESTDIR}${PREFIX}/bin/wasmdump-${PYVERSSUFFIX}

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
