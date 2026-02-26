# $NetBSD: Makefile,v 1.2 2026/02/26 12:47:24 pin Exp $

DISTNAME=	xtop-0.3.1
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/xtop/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mabognar/xtop/
COMMENT=	TODO: Short description of the package
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
