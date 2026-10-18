# $NetBSD: Makefile,v 1.1 2026/10/18 08:00:27 pin Exp $

DISTNAME=	sslx-0.3.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=glincker/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glincker/sslx/
COMMENT=	The modern way to work with certificates and TLS
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

#RUST_REQ=	1.100.0-beta.5
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.100.0-beta.5 on amd64

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
