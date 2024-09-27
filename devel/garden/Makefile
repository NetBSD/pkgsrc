# $NetBSD: Makefile,v 1.15 2024/09/27 11:53:30 pin Exp $

DISTNAME=	garden-1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.8.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64

WRKSRC=		${WRKDIR}/garden-v1.8.0-47bba3f304365d995adfcac11cd18df7ce73209f

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
