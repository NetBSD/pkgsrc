# $NetBSD: Makefile,v 1.4 2025/05/19 09:09:37 pin Exp $

DISTNAME=	lobtui-0.3.1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=pythops/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pythops/lobtui/
COMMENT=	TUI for lobste.rs
LICENSE=	gnu-gpl-v3

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

#RUST_REQ=	1.86.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.86.0 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
