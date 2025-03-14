# $NetBSD: Makefile,v 1.14 2025/03/14 21:00:31 pin Exp $

DISTNAME=	hck-0.11.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sstadick/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sstadick/hck/
COMMENT=	Sharp cut(1) clone
LICENSE=	unlicense OR mit

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasi-0.13.3+wasi-0.2.2.crate=		https://static.crates.io/crates/wasi/

RUST_REQ=	1.81.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
