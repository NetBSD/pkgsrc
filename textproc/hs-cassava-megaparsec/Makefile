# $NetBSD: Makefile,v 1.10 2023/01/26 11:38:08 pho Exp $

DISTNAME=	cassava-megaparsec-2.0.4
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Megaparsec parser of CSV files that plays nicely with Cassava
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	vector

.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
