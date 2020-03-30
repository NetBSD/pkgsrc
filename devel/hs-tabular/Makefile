# $NetBSD: Makefile,v 1.1 2020/03/30 16:46:47 riastradh Exp $

DISTNAME=	tabular-0.2.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=tabular-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kowey/tabular
COMMENT=	Two-dimensional data tables with rendering functions
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../mk/haskell.mk"
.include "../../textproc/hs-csv/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
