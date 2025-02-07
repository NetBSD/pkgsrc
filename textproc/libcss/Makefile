# $NetBSD: Makefile,v 1.1 2025/02/07 16:02:09 pho Exp $

DISTNAME=	libcss-0.9.2-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	textproc
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/projects/libcss/
COMMENT=	CSS parser and selection engine
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake perl pkg-config

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	COMPONENT_TYPE=lib-shared
MAKE_ENV+=	PKGCONFIG=${TOOLS_CMD.pkg-config:Q}

BUILDLINK_TRANSFORM+=	rm:-Werror

TOOL_DEPENDS+=	netsurf-buildsystem-[0-9]*:../../devel/netsurf-buildsystem

.include "../../devel/libwapcaplet/buildlink3.mk"
.include "../../textproc/libparserutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
