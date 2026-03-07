# $NetBSD: Makefile,v 1.35 2026/03/07 13:47:26 pin Exp $

DISTNAME=	cargo-c-0.10.20
# cargo-c v0.10.21 requires Rust >= 1.92
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lu-zero/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/lu-zero/cargo-c
COMMENT=	Build and install C-compatible libraries from Rust lang
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

RUST_REQ=	1.91.0
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGOC_PROGRAMS+=	cargo-capi
CARGOC_PROGRAMS+=	cargo-cbuild
CARGOC_PROGRAMS+=	cargo-cinstall
CARGOC_PROGRAMS+=	cargo-ctest

do-install:
.for f in ${CARGOC_PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${f} ${DESTDIR}${PREFIX}/bin
.endfor

#.include "../../devel/libgit2/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3.0
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
