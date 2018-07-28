# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:43 brook Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rforge.net/uuid/
COMMENT=	Tools for generating and handling of UUIDs
LICENSE=	modified-bsd

R_PKGNAME=	uuid
R_PKGVER=	0.1-2

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.9.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
