# $NetBSD: Makefile,v 1.10 2023/10/29 12:07:49 pho Exp $

DISTNAME=	Glob-0.10.2
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Globbing library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	transformers

.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
