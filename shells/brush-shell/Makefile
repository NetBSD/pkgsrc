# $NetBSD: Makefile,v 1.1 2026/06/11 15:19:44 drixter Exp $

DISTNAME=	brush-shell-v0.4.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=reubeno/}
GITHUB_PROJECT=	brush
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/reubeno/brush/
COMMENT=	POSIX- and bash-compatible shell written in Rust
LICENSE=	mit

RUST_REQ=	1.88.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

PKG_SHELL=	bin/brush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/brush \
		${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
