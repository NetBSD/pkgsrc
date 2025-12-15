# $NetBSD: Makefile,v 1.1 2025/12/15 14:04:23 pin Exp $

DISTNAME=	gravityfile-0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epistates/gravityfile/
COMMENT=	File system analyzer with an interactive TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.91.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.91.1 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
