# $NetBSD: Makefile,v 1.8 2026/10/11 16:02:18 wiz Exp $

DISTNAME=	rust-bindgen-0.72.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-lang/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/rust-lang/rust-bindgen
COMMENT=	Automatically generate Rust FFI bindings to C (and some C++) libraries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "cargo-depends.mk"

RUST_REQ=		1.70.0
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bindgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
BUILDLINK_API_DEPENDS.cairo+=	clang>=21
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
