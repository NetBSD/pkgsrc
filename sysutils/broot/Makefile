# $NetBSD: Makefile,v 1.113 2025/03/30 16:49:56 pin Exp $

DISTNAME=	broot-1.45.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dystroy.org/broot/
COMMENT=	New way to see and navigate directory trees
LICENSE=	mit

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasi-0.14.2+wasi-0.2.4.crate=		https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

RUST_REQ=			1.79.0
USE_TOOLS+=			pkg-config
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxcb}/lib

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/page \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/broot.1

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
