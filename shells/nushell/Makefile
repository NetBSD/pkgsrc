# $NetBSD: Makefile,v 1.62 2024/09/21 21:16:13 pin Exp $

DISTNAME=	nushell-0.98.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

SITES.curl-sys-0.4.73+curl-8.8.0.crate=	https://static.crates.io/crates/curl-sys/

.include "cargo-depends.mk"

RUST_REQ=	1.79.0
USE_TOOLS+=	pkg-config

PKG_SHELL=	bin/nu

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
