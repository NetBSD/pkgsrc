# $NetBSD: Makefile,v 1.31 2025/01/29 21:49:17 pin Exp $

DISTNAME=	tui-journal-0.14.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ammarabouzor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ammarabouzor/tui-journal/
COMMENT=	Your journal app if you live in a terminal
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.81.0
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
