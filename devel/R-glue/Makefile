# $NetBSD: Makefile,v 1.2 2019/04/07 13:19:52 wen Exp $

DISTNAME=	glue_1.3.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tidyverse/glue
COMMENT=	Interpreted String Literals
LICENSE=	mit

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
