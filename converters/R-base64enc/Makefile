# $NetBSD: Makefile,v 1.1 2018/05/31 01:30:33 wen Exp $

DISTNAME=	base64enc_0.1-3
CATEGORIES=	converters

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://www.rforge.net/base64enc
COMMENT=	Tools for base64 encoding
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

BUILDLINK_API_DEPENDS.R+=	R>=2.9.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
