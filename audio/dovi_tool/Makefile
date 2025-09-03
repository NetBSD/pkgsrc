# $NetBSD: Makefile,v 1.1 2025/09/03 14:25:28 ryoon Exp $

DISTNAME=	dovi_tool-2.3.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=quietvoid/}
GITHUB_PROJECT=	dovi_tool
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/quietvoid/dovi_tool/
COMMENT=	CLI tool for Dolby Vision
LICENSE=	mit

TOOL_DEPENDS+=	cargo-c-[0-9]*:../../devel/cargo-c

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
