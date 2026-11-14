# $NetBSD: Makefile,v 1.1 2026/11/14 07:28:05 wiz Exp $

DISTNAME=	emmylua-ls-0.25.1
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmmyLuaLs/}
GITHUB_PROJECT=	emmylua-analyzer-rust
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EmmyLuaLs/emmylua-analyzer-rust
COMMENT=	Language Server for Lua
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.90.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/emmylua_ls \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/emmylua_check \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/emmylua_doc_cli \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
