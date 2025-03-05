# $NetBSD: Makefile,v 1.15 2025/03/05 03:39:54 pho Exp $

DISTNAME=	Glob-0.10.2
PKGREVISION=	8
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Globbing library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	containers	\
	filepath	\
	transformers

.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
