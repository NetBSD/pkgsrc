# $NetBSD: Makefile,v 1.28 2026/05/03 15:00:14 pin Exp $

DISTNAME=	xcp-0.24.8
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
