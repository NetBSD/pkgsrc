# $NetBSD: Makefile,v 1.12 2026/06/18 15:22:03 nia Exp $

DISTNAME=	rgbds-1.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gbdev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rgbds.gbdev.io/
COMMENT=	Assembler/linker package for the Game Boy and Game Boy Color
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config lex bison
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	Q= # Be noisy.
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	YACC=${YACC:Q}
MAKE_FLAGS+=	LEX=${LEX:Q}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

USE_CXX_FEATURES+=	c++20

CHECK_PORTABILITY_SKIP=	test/pokecrystal/tools/compare2.sh

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
