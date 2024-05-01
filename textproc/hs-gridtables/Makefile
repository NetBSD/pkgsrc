# $NetBSD: Makefile,v 1.5 2024/05/01 14:11:25 pho Exp $

DISTNAME=	gridtables-0.1.0.0
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parser for reStructuredText-style grid tables
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
