# $NetBSD: Makefile,v 1.15 2026/04/25 19:03:17 pin Exp $

DISTNAME=	cargo-about-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-about/
COMMENT=	Cargo plugin to generate list of all licenses for a crate
LICENSE=	apache-2.0 OR mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=	1.88.0
USE_TOOLS+=	pkg-config

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		cli

.include "../../lang/rust/cargo.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
