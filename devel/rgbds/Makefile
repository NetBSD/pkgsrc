# $NetBSD: Makefile,v 1.2 2018/08/17 18:17:59 nia Exp $

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

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
