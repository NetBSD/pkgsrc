# $NetBSD: Makefile,v 1.2 2025/08/13 11:07:09 pho Exp $

DISTNAME=	country-codes-0.1.4
PKGREVISION=	1
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
