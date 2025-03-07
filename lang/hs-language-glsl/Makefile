# $NetBSD: Makefile,v 1.1 2025/03/07 18:31:13 pho Exp $

DISTNAME=	language-glsl-0.3.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GLSL abstract syntax tree, parser, and pretty-printer
LICENSE=	modified-bsd

# Don't build or install an example executable.
HASKELL_DISABLE_EXECUTABLES+=	\
	glsl-pprint

.include "../../devel/hs-prettyclass/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
