# $NetBSD: Makefile,v 1.1 2018/01/22 19:22:44 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.auckland.ac.nz/~yee/VGAM/
COMMENT=	Vector Generalized Linear and Additive Models
LICENSE=	gnu-gpl-v2

R_PKGNAME=	VGAM
R_PKGVER=	1.0-4

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=3.4.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
