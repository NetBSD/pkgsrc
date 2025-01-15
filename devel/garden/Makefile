# $NetBSD: Makefile,v 1.19 2025/01/15 21:17:58 pin Exp $

DISTNAME=	garden-1.10.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.10.1/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64

WRKSRC=		${WRKDIR}/garden-v1.10.1-e6472098591e5cbb3e7366a7049fa564c796386f

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
