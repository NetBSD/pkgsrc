# $NetBSD: Makefile,v 1.1 2019/06/09 09:41:35 wen Exp $

CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://github.com/brodieG/fansi
COMMENT=	ANSI Control Sequence Aware String Functions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	fansi
R_PKGVER=	0.4.0

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
