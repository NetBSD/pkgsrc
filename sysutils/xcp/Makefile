# $NetBSD: Makefile,v 1.29 2026/10/28 18:03:46 pin Exp $

DISTNAME=	xcp-0.24.9
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
