# $NetBSD: Makefile,v 1.2 2026/09/06 14:03:08 pin Exp $

DISTNAME=	disko-0.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cesarferreira/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cesarferreira/disko/
COMMENT=	Disk usage TUI that shows what is full and what is using it
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
