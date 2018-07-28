# $NetBSD: Makefile,v 1.3 2018/07/28 14:40:46 brook Exp $

CATEGORIES=	math

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.auckland.ac.nz/~yee/VGAM/
COMMENT=	Vector Generalized Linear and Additive Models
LICENSE=	gnu-gpl-v2

R_PKGNAME=	VGAM
R_PKGVER=	1.0-5

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=3.4.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
