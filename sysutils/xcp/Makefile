# $NetBSD: Makefile,v 1.23 2025/04/02 11:37:12 pin Exp $

DISTNAME=	xcp-0.24.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tarka/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tarka/xcp/
COMMENT=	Extended cp
LICENSE=	gnu-gpl-v3

SITES.wasi-0.14.2+wasi-0.2.4.crate=		https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

RUST_REQ=	1.75.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
