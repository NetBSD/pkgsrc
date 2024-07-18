# $NetBSD: Makefile,v 1.2 2024/07/18 09:59:34 pin Exp $

DISTNAME=	scriptisto-2.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=igor-petruk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/igor-petruk/scriptisto/
COMMENT=	Language-agnostic interpreter to write scripts in compiled languages
LICENSE=	apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_LANGUAGES=	c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
