# $NetBSD: Makefile,v 1.11 2025/01/22 04:36:10 pin Exp $

DISTNAME=	hck-0.11.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sstadick/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sstadick/hck/
COMMENT=	Sharp cut(1) clone
LICENSE=	unlicense OR mit

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

RUST_REQ=	1.81.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
