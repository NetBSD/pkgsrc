# $NetBSD: Makefile,v 1.6 2018/05/09 18:08:19 minskim Exp $

DISTNAME=	DBI_1.0.0
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://r-dbi.github.io/DBI
COMMENT=	R Database Interface
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
