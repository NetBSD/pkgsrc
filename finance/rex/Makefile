# $NetBSD: Makefile,v 1.28 2026/03/02 12:10:14 pin Exp $

DISTNAME=	rex-0.2.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheRustyPickle/}
GITHUB_PROJECT=	Rex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TheRustyPickle/Rex/
COMMENT=	TUI for keeping track of incomes and expenses
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

#RUST_REQ=	1.93.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.93.1 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.wayland}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rex ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
