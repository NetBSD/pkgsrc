# $NetBSD: Makefile,v 1.4 2025/03/05 03:39:35 pho Exp $

DISTNAME=	validation-selective-0.2.0.0
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lighweight pure data validation
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	deepseq	\
	selective

.include "../../devel/hs-selective/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
