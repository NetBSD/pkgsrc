# $NetBSD: Makefile,v 1.17 2024/11/08 09:01:39 pin Exp $

DISTNAME=	garden-1.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.9.1/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64

WRKSRC=		${WRKDIR}/garden-v1.9.1-59ab73065cc7df69fc063f4d50aa7160ebdeeb41

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
