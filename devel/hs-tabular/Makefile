# $NetBSD: Makefile,v 1.8 2023/02/07 01:40:51 pho Exp $

DISTNAME=	tabular-0.2.2.8
PKGREVISION=	5
CATEGORIES=	devel textproc # XXX: Should be moved to textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Two-dimensional data tables with rendering functions
LICENSE=	modified-bsd

.include "../../mk/haskell.mk"
.include "../../textproc/hs-csv/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
