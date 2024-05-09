# $NetBSD: Makefile,v 1.6 2024/05/09 01:31:40 pho Exp $

DISTNAME=	deriving-aeson-0.2.9
PKGREVISION=	4
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Type driven generic aeson instance customisation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
