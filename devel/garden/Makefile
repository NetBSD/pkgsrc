# $NetBSD: Makefile,v 1.20 2025/01/29 21:52:01 pin Exp $

DISTNAME=	garden-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.0.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64

WRKSRC=		${WRKDIR}/garden-v2.0.0-6947f8bc20f0d01482516df6880a4303e5bb26e4

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
