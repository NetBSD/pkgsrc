# $NetBSD: Makefile,v 1.10 2026/06/27 14:49:44 pin Exp $

DISTNAME=	redox-0.6.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=JackDerksen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JackDerksen/redox/
COMMENT=	Terminal-based text editor, built with MinUI
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.97.0-beta.4
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.97.0-beta.4 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
