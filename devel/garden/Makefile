# $NetBSD: Makefile,v 1.14 2024/07/18 09:56:17 pin Exp $

DISTNAME=	garden-1.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.7.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

WRKSRC=		${WRKDIR}/garden-v1.7.0-9dd08ca835769c2df7f0b8cc8e328c5a31bd170a

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
