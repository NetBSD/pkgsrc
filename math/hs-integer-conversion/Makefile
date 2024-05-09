# $NetBSD: Makefile,v 1.3 2024/05/09 01:32:26 pho Exp $

DISTNAME=	integer-conversion-0.1.0.1
PKGREVISION=	2
CATEGORIES=	math converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Conversion from strings to Integer
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring \
	primitive

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
