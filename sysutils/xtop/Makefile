# $NetBSD: Makefile,v 1.7 2026/04/20 12:26:44 pin Exp $

DISTNAME=	xtop-0.3.9
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
