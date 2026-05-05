# $NetBSD: Makefile,v 1.3 2026/05/05 10:06:57 pin Exp $

DISTNAME=	eilmeldung-1.5.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=christo-auer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/christo-auer/eilmeldung/
COMMENT=	TUI RSS reader based on the news-flash library
LICENSE=	gnu-gpl-v3

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

.include "cargo-depends.mk"

#RUST_REQ=	1.96.0-beta.5
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.96.0-beta.5 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
