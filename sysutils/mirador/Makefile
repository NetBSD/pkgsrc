# $NetBSD: Makefile,v 1.8 2026/09/19 15:40:06 pin Exp $

DISTNAME=	mirador-1.16.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jchultarsky/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jchultarsky/mirador/
COMMENT=	Personal dashboard for your terminal
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.95.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
