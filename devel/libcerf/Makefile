# $NetBSD: Makefile,v 1.6 2018/12/01 21:22:36 gson Exp $

DISTNAME=	libcerf-1.7
CATEGORIES=	devel math
MASTER_SITES=	http://apps.jcns.fz-juelich.de/src/libcerf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.0rg
HOMEPAGE=	http://apps.jcns.fz-juelich.de/doku/sc/libcerf
COMMENT=	Library providing efficient and accurate complex error functions
LICENSE=	mit

USE_LANGUAGES=		c99
USE_CMAKE=		yes
CMAKE_ARG_PATH=		${WRKSRC}
CONFIGURE_DIRS=		${WRKDIR}/build

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
