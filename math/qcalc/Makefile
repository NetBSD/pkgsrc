# $NetBSD: Makefile,v 1.12 2025/04/04 20:01:39 pin Exp $

DISTNAME=	qcalc-0.15.2
CATEGORIES=	math
MASTER_SITES=	https://static.crates.io/crates/qcalc/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OchirErkhembayar/qcalc/
COMMENT=	Terminal GUI calculator
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
