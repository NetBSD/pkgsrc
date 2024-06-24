# $NetBSD: Makefile,v 1.9 2024/06/24 06:26:59 pin Exp $

DISTNAME=	hck-0.10.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sstadick/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	a17eeb927b8a4e5d573c0bfb2e0d0e952c10f930

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sstadick/hck/
COMMENT=	Sharp cut(1) clone
LICENSE=	unlicense OR mit

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
