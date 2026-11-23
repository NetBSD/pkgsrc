# $NetBSD: Makefile,v 1.7 2026/11/23 12:38:14 pin Exp $

DISTNAME=	gravityfile-0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epistates/gravityfile/
COMMENT=	File system analyzer with an interactive TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

CFLAGS+=	-Wno-implicit-function-declaration

RUST_REQ=	1.90

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
