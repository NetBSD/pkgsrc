# $NetBSD: Makefile,v 1.9 2025/04/12 21:37:07 adam Exp $

DISTNAME=	wasm-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=athre0z/}
GITHUB_PROJECT=	wasm
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/athre0z/wasm
COMMENT=	WebAssembly decoder & disassembler
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c++

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/wasmdump \
		${DESTDIR}${PREFIX}/bin/wasmdump-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
