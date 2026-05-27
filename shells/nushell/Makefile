# $NetBSD: Makefile,v 1.87 2026/05/27 04:53:05 adam Exp $

DISTNAME=	nushell-0.113.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

RUST_REQ=	1.93.1
USE_TOOLS+=	pkg-config

MAKE_ENV+=	LIBGIT2_NO_VENDOR=1
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

PKG_SHELL=	bin/nu

ARGMAX_REQ=	1048576

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
