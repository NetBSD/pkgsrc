# $NetBSD: Makefile,v 1.13 2026/10/10 11:25:24 adam Exp $

DISTNAME=	libhangul-0.2.0
CATEGORIES=	inputmethod korean
MASTER_SITES=	${MASTER_SITE_GITHUB:=libhangul/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/libhangul/libhangul
COMMENT=	Library used by Korean input methods
LICENSE=	gnu-lgpl-v2.1

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libhangul.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
