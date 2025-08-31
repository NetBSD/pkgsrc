# $NetBSD: Makefile,v 1.1 2025/08/31 12:03:34 ryoon Exp $

DISTNAME=	dovi_tool-2.3.0
PKGNAME=	libdovi-2.3.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=quietvoid/}
GITHUB_PROJECT=	dovi_tool
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/quietvoid/dovi_tool/
COMMENT=	Librtary for Dolby Vision metadata parsing and writing
LICENSE=	mit

TOOL_DEPENDS+=	cargo-c-[0-9]*:../../devel/cargo-c

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/dolby_vision

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib

CARGOC_ARGS+=	--release --destdir ${DESTDIR} --prefix ${PREFIX}
CARGOC_ARGS+=	--libdir ${PREFIX}/lib
CARGOC_ARGS+=	--library-type=cdylib

.PHONY: do-cargoc-build
do-cargoc-build:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} \
		cbuild ${CARGOC_ARGS} ${DEFAULT_CARGO_ARGS}

do-build: do-cargoc-build

.PHONY: do-cargoc-install
do-cargoc-install:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} \
		cinstall ${CARGOC_ARGS} ${DEFAULT_CARGO_ARGS}

do-install: do-cargoc-install

.include "../../lang/rust/cargo.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
