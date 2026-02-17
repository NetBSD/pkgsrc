# $NetBSD: Makefile,v 1.27 2026/02/17 13:58:17 pin Exp $

DISTNAME=	xcp-0.24.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tarka/}
GITHUB_TAG=	xcp-v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tarka/xcp/
COMMENT=	Extended cp
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
