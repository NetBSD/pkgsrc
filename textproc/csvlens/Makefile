# $NetBSD: Makefile,v 1.30 2025/05/31 13:34:02 pin Exp $

DISTNAME=	csvlens-0.13.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=YS-L/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/YS-L/csvlens/
COMMENT=	Command line csv viewer
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.87.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.87.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
