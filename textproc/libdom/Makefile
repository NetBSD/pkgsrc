# $NetBSD: Makefile,v 1.1 2025/02/07 16:03:46 pho Exp $

DISTNAME=	libdom-0.4.2-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	textproc
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/projects/libdom/
COMMENT=	Implementation of the W3C DOM
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake pkg-config

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	COMPONENT_TYPE=lib-shared
MAKE_ENV+=	PKGCONFIG=${TOOLS_CMD.pkg-config:Q}

TOOL_DEPENDS+=	netsurf-buildsystem-[0-9]*:../../devel/netsurf-buildsystem

.include "../../devel/libwapcaplet/buildlink3.mk"
.include "../../textproc/libparserutils/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/libhubbub/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
