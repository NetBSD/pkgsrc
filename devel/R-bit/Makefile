# $NetBSD: Makefile,v 1.2 2018/07/04 08:13:59 wen Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ff.r-forge.r-project.org/
COMMENT=	Class for vectors of 1-bit booleans
LICENSE=	gnu-gpl-v2

R_PKGNAME=	bit
R_PKGVER=	1.1-14

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.9.2
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
