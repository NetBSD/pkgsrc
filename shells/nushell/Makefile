# $NetBSD: Makefile,v 1.53 2024/04/11 09:06:33 pin Exp $

# Please don't update to 0.92.2
# The latest version has Rust-1.77.2 as minimum required version.
# This is due to CVE-2024-24576 that only affects Windows.
# see, https://blog.rust-lang.org/2024/04/09/cve-2024-24576.html
DISTNAME=	nushell-0.92.1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

PKG_SHELL=		bin/nu

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
