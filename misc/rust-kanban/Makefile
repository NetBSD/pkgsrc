# $NetBSD: Makefile,v 1.9 2024/02/23 10:04:23 pin Exp $

DISTNAME=	rust-kanban-0.9.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yashs662/}
GITHUB_PROJECT=	rust_kanban
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/yashs662/rust_kanban/
COMMENT=	Kanban board for the terminal
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
