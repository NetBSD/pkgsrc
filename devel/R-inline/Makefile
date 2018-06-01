# $NetBSD: Makefile,v 1.2 2018/06/01 02:02:11 wen Exp $

DISTNAME=	inline_0.3.15
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions to Inline C, C++, Fortran Function Calls from R
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.4.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
