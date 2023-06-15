# $NetBSD: Makefile,v 1.10 2023/06/15 07:09:35 pin Exp $

DISTNAME=	erdtree-3.0.1
# Newer versions require Rust-1.70 to build
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=solidiquis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/solidiquis/erdtree/
COMMENT=	Multi-threaded file-tree visualizer and disk usage analyzer
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
