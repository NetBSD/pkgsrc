# $NetBSD: Makefile,v 1.3 2021/04/23 10:31:55 pho Exp $

DISTNAME=	pretty-show-1.10
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Tools for working with derived Show instances
LICENSE=	mit

BUILD_DEPENDS+=	happy-[0-9]*:../../devel/happy

.include "../../devel/hs-haskell-lexer/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
