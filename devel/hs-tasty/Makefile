# $NetBSD: Makefile,v 1.15 2024/04/30 13:34:16 pho Exp $

DISTNAME=	tasty-1.5
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern and extensible testing framework
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ansi-terminal

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
