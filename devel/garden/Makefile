# $NetBSD: Makefile,v 1.16 2024/10/12 22:56:21 pin Exp $

DISTNAME=	garden-1.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.9.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64

WRKSRC=		${WRKDIR}/garden-v1.9.0-83c7891502d07cd5665be395ce6b3e163e7f8148

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
