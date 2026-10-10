# $NetBSD: Makefile,v 1.14 2026/10/10 06:38:06 pin Exp $

DISTNAME=	qcalc-0.15.4
CATEGORIES=	math
MASTER_SITES=	https://static.crates.io/crates/qcalc/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OchirErkhembayar/qcalc/
COMMENT=	Terminal GUI calculator
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.100.0beta.4
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.100.0beta.4 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
