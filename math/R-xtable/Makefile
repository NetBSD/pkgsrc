# $NetBSD: Makefile,v 1.3 2018/08/30 12:36:31 wen Exp $

CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xtable.r-forge.r-project.org/
COMMENT=	Export Tables to LaTeX or HTML
LICENSE=	gnu-gpl-v2

R_PKGNAME=	xtable
R_PKGVER=	1.8-3

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
