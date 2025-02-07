# $NetBSD: Makefile,v 1.1 2025/02/07 16:01:08 pho Exp $

DISTNAME=	libparserutils-0.2.5-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	textproc
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/projects/libparserutils/
COMMENT=	Library for building efficient parsers
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake perl

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	COMPONENT_TYPE=lib-shared

BUILDLINK_TRANSFORM+=	rm:-Werror

TOOL_DEPENDS+=	netsurf-buildsystem-[0-9]*:../../devel/netsurf-buildsystem

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
