# $NetBSD: Makefile,v 1.1 2018/04/18 15:37:56 minskim Exp $

DISTNAME=	inline_0.3.14
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions to Inline C, C++, Fortran Function Calls from R
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.4.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
