# $NetBSD: Makefile,v 1.21 2025/10/12 12:28:21 pin Exp $

DISTNAME=	rex-0.2.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheRustyPickle/}
GITHUB_PROJECT=	Rex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TheRustyPickle/Rex/
COMMENT=	TUI for keeping track of incomes and expenses
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.90.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.90.0 on amd64
USE_TOOLS+=	pkg-config
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
