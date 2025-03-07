# $NetBSD: Makefile,v 1.1 2025/03/07 13:19:24 pho Exp $

DISTNAME=	country-codes-0.1.4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	ISO 3166 country codes and i18n names
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	shakespeare

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
