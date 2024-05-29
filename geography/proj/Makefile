# $NetBSD: Makefile,v 1.40 2024/05/29 16:32:48 adam Exp $

# An update to 9 is on hold until I can assess if it causes trouble.
VERSION_BASE=	8.2.1
# Accomodate testing RCs, whcih have names like 9.0RC1 and unpack to
# 9.0.
VERSION_RC=
VERSION=	${VERSION_BASE}${VERSION_RC}
WRKFINAL=	proj-${VERSION_BASE}
WRKSRC=		${WRKDIR}/${WRKFINAL}
DISTNAME=	proj-${VERSION}
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://proj.org/
COMMENT=	Cartographic projection software
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

PREV_PKGPATH=		misc/proj

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

# \todo GC this after resolving test issues.
#.if ${OPSYS} == "NetBSD"
#CFLAGS+=		-DHAVE_C99_MATH=0
#.endif

# \todo Document, file uprsteam, and add uptream bug report URL.
CXXFLAGS.SunOS+=	-fpermissive

# \todo Debug geodtest failure, after we are up to date.
TEST_TARGET=		check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
