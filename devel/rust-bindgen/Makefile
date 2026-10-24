# $NetBSD: Makefile,v 1.9 2026/10/24 17:11:47 pin Exp $

DISTNAME=	rust-bindgen-0.73.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/rust-lang/rust-bindgen
COMMENT=	Automatically generate Rust FFI bindings to C (and some C++) libraries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "cargo-depends.mk"

RUST_REQ=		1.71.0
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bindgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
BUILDLINK_API_DEPENDS.cairo+=	clang>=21
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
