# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:51 brook Exp $

CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xtable.r-forge.r-project.org/
COMMENT=	Export Tables to LaTeX or HTML
LICENSE=	gnu-gpl-v2

R_PKGNAME=	xtable
R_PKGVER=	1.8-2

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
