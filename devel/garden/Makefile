# $NetBSD: Makefile,v 1.18 2024/12/24 18:29:06 pin Exp $

DISTNAME=	garden-1.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.10.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64

WRKSRC=		${WRKDIR}/garden-v1.10.0-341784ebe8215f51b141472317ffc6bf4c85573b

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
