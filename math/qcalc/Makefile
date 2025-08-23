# $NetBSD: Makefile,v 1.13 2025/08/23 20:27:39 pin Exp $

DISTNAME=	qcalc-0.15.3
CATEGORIES=	math
MASTER_SITES=	https://static.crates.io/crates/qcalc/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OchirErkhembayar/qcalc/
COMMENT=	Terminal GUI calculator
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.89.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.89.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
