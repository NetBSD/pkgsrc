# $NetBSD: Makefile,v 1.36 2025/07/30 06:50:58 pin Exp $

DISTNAME=	tui-journal-0.16.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ammarabouzor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ammarabouzor/tui-journal/
COMMENT=	Your journal app if you live in a terminal
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
