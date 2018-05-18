# $NetBSD: Makefile,v 1.1 2018/05/18 01:00:59 minskim Exp $

DISTNAME=	glue_1.2.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tidyverse/glue
COMMENT=	Interpreted String Literals
LICENSE=	mit

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
