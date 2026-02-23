# $NetBSD: Makefile,v 1.16 2026/02/23 08:33:58 pin Exp $

DISTNAME=	cargo-nextest-0.9.129
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nextest-rs/}
GITHUB_PROJECT=	nextest
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://nexte.st/
COMMENT=	Next-generation test runner for Rust
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.91.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

# Alpine and Arch Linux use '--no-default-features --features default-no-update' to build their packages.
# See, https://gitlab.alpinelinux.org/alpine/aports/-/raw/master/main/cargo-nextest/APKBUILD
# or, https://gitlab.archlinux.org/archlinux/packaging/packages/cargo-nextest/-/raw/main/PKGBUILD?ref_type=heads
#
# But, upstream states:
# We specify default-no-update here because if users just run:
# cargo build --no-default-features --features default-no-update then cargo will unify features for
# cargo-nextest, and it will be built with self-update enabled.
# We could ask distributors to always include `--package cargo-nextest` instead, but they're likely
# to forget.
# None of our current tests depend on self-update, so just don't include it by default.
#
# Reference, https://raw.githubusercontent.com/nextest-rs/nextest/refs/heads/main/Cargo.toml
#
# So, lets stick to what upstream recommends.
# CARGO_NO_DEFAULT_FEATURES=	YES
# CARGO_FEATURES+=		default-no-update

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-nextest \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
