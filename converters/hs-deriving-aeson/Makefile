# $NetBSD: Makefile,v 1.4 2023/10/30 13:26:18 pho Exp $

DISTNAME=	deriving-aeson-0.2.9
PKGREVISION=	2
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Type driven generic aeson instance customisation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
