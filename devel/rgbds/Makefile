# $NetBSD: Makefile,v 1.7 2020/04/12 11:32:30 nia Exp $

DISTNAME=	rgbds-0.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rednex/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rednex.github.io/rgbds/
COMMENT=	Assembler/linker package for the Game Boy and Game Boy Color
LICENSE=	mit

WRKSRC=		${WRKDIR}/rgbds
USE_TOOLS+=	gmake pkg-config lex bison

MAKE_FLAGS+=	Q= # Be noisy.
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	YACC=${YACC}
MAKE_FLAGS+=	LEX=${LEX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

CHECK_PORTABILITY_SKIP=	test/pokecrystal/tools/compare2.sh

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
