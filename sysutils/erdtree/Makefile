# $NetBSD: Makefile,v 1.11 2023/07/10 19:36:18 pin Exp $

DISTNAME=	erdtree-3.1.2
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
