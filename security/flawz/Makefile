# $NetBSD: Makefile,v 1.10 2026/06/14 15:08:16 pin Exp $

DISTNAME=	flawz-0.4.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/orhun/flawz/
COMMENT=	TUI for browsing security vulnerabilities
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.88.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
