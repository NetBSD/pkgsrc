# $NetBSD: Makefile,v 1.10 2023/10/23 06:37:53 wiz Exp $

DISTNAME=	jless-0.9.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaulJuliusMartinez/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PaulJuliusMartinez/jless/
COMMENT=	Command-line pager for JSON data
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c c++
USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxcb}/lib

# jless command conflicts with misc/ja-less
# Rename it at install time

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jless \
		${DESTDIR}${PREFIX}/bin/j_less

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
