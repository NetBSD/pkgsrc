# $NetBSD: Makefile,v 1.19 2026/11/13 14:38:47 pho Exp $

DISTNAME=	async-2.2.5
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Run IO operations asynchronously and wait for their results
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
