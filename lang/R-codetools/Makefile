# $NetBSD: Makefile,v 1.1 2018/07/15 21:22:46 minskim Exp $

DISTNAME=	codetools_0.2-15
CATEGORIES=	lang

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Code Analysis Tools for R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
