# $NetBSD: Makefile,v 1.29 2026/08/17 07:16:34 pin Exp $

DISTNAME=	lla-0.5.12
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/lla/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lla.chaqchase.com/docs/about/introduction
COMMENT=	The Elegant ls Alternative
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

#RUST_REQ=	1.98.0-beta.7
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.98.0-beta.7 on amd64
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
