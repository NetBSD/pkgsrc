# $NetBSD: Makefile,v 1.7 2022/02/26 03:58:08 pho Exp $

DISTNAME=	tabular-0.2.2.8
PKGREVISION=	4
CATEGORIES=	devel textproc # XXX: Should be moved to textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Two-dimensional data tables with rendering functions
LICENSE=	modified-bsd

.include "../../mk/haskell.mk"
.include "../../textproc/hs-csv/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
