# $NetBSD: Makefile,v 1.3 2018/10/03 13:17:06 nia Exp $

DISTNAME=	rgbds-0.3.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rednex/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rednex/rgbds
COMMENT=	Assembler/linker package for the Game Boy and Game Boy Color
LICENSE=	mit

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake pkg-config lex yacc

MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
