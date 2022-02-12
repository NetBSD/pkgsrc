# $NetBSD: Makefile,v 1.7 2022/02/12 08:50:51 pho Exp $

DISTNAME=	cassava-megaparsec-2.0.4
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Megaparsec parser of CSV files that plays nicely with Cassava
LICENSE=	mit

.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
