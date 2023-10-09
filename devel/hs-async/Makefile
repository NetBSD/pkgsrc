# $NetBSD: Makefile,v 1.11 2023/10/09 04:54:07 pho Exp $

DISTNAME=	async-2.2.4
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Run IO operations asynchronously and wait for their results
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
