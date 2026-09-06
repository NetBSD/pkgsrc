# $NetBSD: Makefile,v 1.14 2026/09/06 14:04:05 pin Exp $

DISTNAME=	dusage-0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mihaigalos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mihaigalos/dusage/
COMMENT=	Command line disk usage information tool
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.99.0-beta.3
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.99.0-beta.3 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
