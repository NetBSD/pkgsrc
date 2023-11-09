# $NetBSD: Makefile,v 1.12 2023/11/09 19:26:00 schmonz Exp $

DISTNAME=	libowfat-0.33
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://www.fefe.de/libowfat/
COMMENT=	Library of general purpose APIs
LICENSE=	gnu-gpl-v2

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

post-extract:
	cd ${WRKSRC}; \
	${MV} tai/tai_now.3 tai/tai_now_libowfat.3; \
	${MV} tai/tai_pack.3 tai/tai_pack_libowfat.3; \
	${MV} taia/taia_now.3 taia/taia_now_libowfat.3; \
	${MV} taia/taia_pack.3 taia/taia_pack_libowfat.3

# work around missing dependency for parallel builds
pre-build:
	cd ${WRKSRC}; \
	${BUILD_MAKE_CMD} headers; \
	${BUILD_MAKE_CMD} ent

.include "../../mk/bsd.pkg.mk"
