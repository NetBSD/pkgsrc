# $NetBSD: Makefile,v 1.16 2026/11/13 14:39:19 pho Exp $

DISTNAME=	tabular-0.2.2.8
PKGREVISION=	12
CATEGORIES=	devel textproc # XXX: Should be moved to textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Two-dimensional data tables with rendering functions
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	mtl

.include "../../mk/haskell.mk"
.include "../../textproc/hs-csv/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
