# $NetBSD: Makefile,v 1.2 2024/05/09 01:31:41 pho Exp $

DISTNAME=	microaeson-0.1.0.1
PKGREVISION=	1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tiny JSON library with light dependency footprint
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	alex

.include "../../devel/hs-fail/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
