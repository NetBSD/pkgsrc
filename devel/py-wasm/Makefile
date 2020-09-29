# $NetBSD: Makefile,v 1.2 2020/09/29 19:28:11 jperkin Exp $

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

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_LANGUAGES=	c++

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/wasmdump \
		${DESTDIR}${PREFIX}/bin/wasmdump-${PYVERSSUFFIX}

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
