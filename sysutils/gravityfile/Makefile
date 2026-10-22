# $NetBSD: Makefile,v 1.5 2026/10/22 08:16:22 pin Exp $

DISTNAME=	gravityfile-0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/gravityfile/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epistates/gravityfile/
COMMENT=	File system analyzer with an interactive TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

CFLAGS+=	-Wno-implicit-function-declaration

RUST_REQ=	1.90.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
