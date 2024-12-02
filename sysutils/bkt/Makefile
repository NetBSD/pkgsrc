# $NetBSD: Makefile,v 1.11 2024/12/02 14:05:20 pin Exp $

DISTNAME=	bkt-0.8.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dimo414/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bkt.rs/
COMMENT=	Subprocess caching utility
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
