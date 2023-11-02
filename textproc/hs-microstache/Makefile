# $NetBSD: Makefile,v 1.1 2023/11/02 02:38:27 pho Exp $

DISTNAME=	microstache-1.0.2.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mustache templates for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson	\
	base

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
