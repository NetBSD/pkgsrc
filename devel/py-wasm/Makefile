# $NetBSD: Makefile,v 1.4 2020/10/08 22:06:38 khorben Exp $

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
		${DESTDIR}${PREFIX}/bin/wasmdump-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
