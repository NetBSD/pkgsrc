# $NetBSD: Makefile,v 1.12 2025/04/02 17:40:04 pin Exp $

DISTNAME=	erdtree-3.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=solidiquis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/solidiquis/erdtree/
COMMENT=	Multi-threaded file-tree visualizer and disk usage analyzer
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
