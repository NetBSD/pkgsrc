# $NetBSD: Makefile,v 1.1 2024/05/06 14:46:44 nikita Exp $

DISTNAME=	cargo-zigbuild-0.18.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-cross/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/rust-cross/cargo-zigbuild
COMMENT=	Compile Cargo project with zig as linker
LICENSE=	mit

DEPENDS+=	zig-[0-9]*:../../lang/zig

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
