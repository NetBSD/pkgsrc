# $NetBSD: Makefile,v 1.6 2025/03/15 15:59:40 pin Exp $

DISTNAME=	feluda-1.5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=anistark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anistark/feluda/
COMMENT=	Detect license usage restrictions in your project
LICENSE=	mit

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasi-0.13.3+wasi-0.2.2.crate=		https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
