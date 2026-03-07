# $NetBSD: Makefile,v 1.4 2026/03/07 17:38:42 pin Exp $

DISTNAME=	xtop-0.3.6
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/xtop/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mabognar/xtop/
COMMENT=	System monitor written in Rust using TUI
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
