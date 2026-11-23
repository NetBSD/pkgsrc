# $NetBSD: Makefile,v 1.2 2026/11/23 16:43:58 adam Exp $

DISTNAME=	pnpm-12.23.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pnpm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pnpm.io/
COMMENT=	Fast, disk space efficient package manager
LICENSE=	mit

TOOL_DEPENDS+=	esbuild>=0.28:../../www/esbuild

RUST_REQ=	1.98
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

CARGO_ARGS=	build --release --bin pnpm ${DEFAULT_CARGO_ARGS}

CARGO_GITHUB_CRATES+=	pnpm dashmap 4401b5c0b2626266dd5d5a9202677bca8b53e57a
CARGO_GITHUB_CRATES+=	pnpm libsql ab8a7516c7d32d6fdd0f68d59956c6233f9f11d4
CARGO_GITHUB_CRATES+=	pnpm node-semver-rs 3d74d6b7f4de1de2006cf2f7663aac09de65b1f6

# Required to generate cas-loader.mjs.inc.
ENHANCED_RESOLVE_VER=	5.26.0
# TODO: This version is not same as what pnpm uses. pnpm uses patched version.
GRACEFUL_FS_VER=	4.2.11
TAPABLE_VER=		2.3.3
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		enhanced-resolve-${ENHANCED_RESOLVE_VER}.tgz
DISTFILES+=		graceful-fs-${GRACEFUL_FS_VER}.tgz
DISTFILES+=		tapable-${TAPABLE_VER}.tgz

SITES.enhanced-resolve-${ENHANCED_RESOLVE_VER}.tgz=	https://registry.npmjs.org/enhanced-resolve/-/
SITES.graceful-fs-${GRACEFUL_FS_VER}.tgz=		https://registry.npmjs.org/graceful-fs/-/
SITES.tapable-${TAPABLE_VER}.tgz=			https://registry.npmjs.org/tapable/-/

EXTRACT_DIR.enhanced-resolve-${ENHANCED_RESOLVE_VER}.tgz=	${WRKDIR}/enhanced-resolve
EXTRACT_DIR.graceful-fs-${GRACEFUL_FS_VER}.tgz=			${WRKDIR}/graceful-fs
EXTRACT_DIR.tapable-${TAPABLE_VER}.tgz=				${WRKDIR}/tapable

post-extract:
	@${STEP_MSG} "Relocating npm packages for esbuild"
	${MKDIR} ${WRKSRC}/pnpm/esm-loader/node_modules
	${MV} ${WRKDIR}/enhanced-resolve/package ${WRKSRC}/pnpm/esm-loader/node_modules/enhanced-resolve
	${MV} ${WRKDIR}/graceful-fs/package ${WRKSRC}/pnpm/esm-loader/node_modules/graceful-fs
	${MV} ${WRKDIR}/tapable/package ${WRKSRC}/pnpm/esm-loader/node_modules/tapable

pre-build:
	@${STEP_MSG} "Bundling cas-loader.mjs.inc by esbuild"
	${RUN}cd ${WRKSRC}/pnpm/esm-loader && \
	esbuild --minify --bundle --platform=node --format=esm \
	--banner:js="import { createRequire as bootstrapRequire } from 'node:module'; const require = bootstrapRequire(import.meta.url);" install-register.mjs \
	--outfile=../crates/deps-restorer/src/cas-loader.mjs.inc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pnpm ${DESTDIR}${PREFIX}/bin
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pn
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pnx
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pnpx

.include "cargo-depends.mk"

.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
