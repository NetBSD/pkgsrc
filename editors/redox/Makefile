# $NetBSD: Makefile,v 1.7 2026/04/20 12:18:42 pin Exp $

DISTNAME=	redox-0.5.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=JackDerksen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JackDerksen/redox/
COMMENT=	Terminal-based text editor, built with MinUI
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.95.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.95.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
