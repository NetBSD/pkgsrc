# $NetBSD: Makefile,v 1.1 2025/02/07 15:59:47 pho Exp $

DISTNAME=	libwapcaplet-0.4.3-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	devel
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/projects/libwapcaplet/
COMMENT=	String internment library
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	COMPONENT_TYPE=lib-shared

BUILDLINK_TRANSFORM+=	rm:-Werror

TOOL_DEPENDS+=	netsurf-buildsystem-[0-9]*:../../devel/netsurf-buildsystem

.include "../../mk/bsd.pkg.mk"
