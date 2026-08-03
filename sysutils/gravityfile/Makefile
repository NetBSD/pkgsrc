# $NetBSD: Makefile,v 1.4 2026/08/03 14:05:04 pin Exp $

DISTNAME=	gravityfile-0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epistates/gravityfile/
COMMENT=	File system analyzer with an interactive TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

CFLAGS+=	-Wno-implicit-function-declaration

#RUST_REQ=	1.98.0-beta.6
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.98.0-beta.6 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
