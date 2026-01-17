# $NetBSD: Makefile,v 1.3 2026/01/17 20:58:14 pin Exp $

DISTNAME=	gravityfile-0.2.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epistates/gravityfile/
COMMENT=	File system analyzer with an interactive TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.92.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.92.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
