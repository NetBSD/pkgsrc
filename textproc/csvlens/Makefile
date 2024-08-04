# $NetBSD: Makefile,v 1.25 2024/08/04 09:46:29 pin Exp $

DISTNAME=	csvlens-0.10.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=YS-L/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/YS-L/csvlens/
COMMENT=	Command line csv viewer
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
