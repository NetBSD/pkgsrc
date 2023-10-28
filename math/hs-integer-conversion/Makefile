# $NetBSD: Makefile,v 1.1 2023/10/28 14:33:14 pho Exp $

DISTNAME=	integer-conversion-0.1.0.1
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
