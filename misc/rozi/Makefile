# $NetBSD: Makefile,v 1.3 2026/09/19 15:39:07 pin Exp $

DISTNAME=	rozi-0.0.22
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tui-lipan/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rozi.tui-lipan.dev/
COMMENT=	Modern tiling terminal multiplexer that feels like a wm
LICENSE=	mpl-2.0

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=	1.90.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
