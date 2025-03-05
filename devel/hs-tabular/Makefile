# $NetBSD: Makefile,v 1.14 2025/03/05 03:39:30 pho Exp $

DISTNAME=	tabular-0.2.2.8
PKGREVISION=	10
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
