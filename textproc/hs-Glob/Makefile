# $NetBSD: Makefile,v 1.16 2025/08/13 11:07:26 pho Exp $

DISTNAME=	Glob-0.10.2
PKGREVISION=	9
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
