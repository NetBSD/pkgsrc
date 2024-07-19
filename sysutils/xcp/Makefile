# $NetBSD: Makefile,v 1.18 2024/07/19 09:52:22 pin Exp $

DISTNAME=	xcp-0.21.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tarka/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tarka/xcp/
COMMENT=	Extended cp
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.75.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
