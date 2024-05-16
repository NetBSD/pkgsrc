# $NetBSD: Makefile,v 1.38 2024/05/16 06:14:59 wiz Exp $

# An update to 8 or 9 is on hold because I have not yet assessed how
# much trouble it will cause.  -gdt
VERSION_BASE=	7.2.1
VERSION_RC=
VERSION=	${VERSION_BASE}${VERSION_RC}
#PKGREVISION=	0
# proj RCs have names like 5.1.0RC1 but unpack to 5.1.0
WRKFINAL=	proj-${VERSION_BASE}
WRKSRC=		${WRKDIR}/${WRKFINAL}
DISTNAME=	proj-${VERSION}
PKGREVISION=	7
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://proj.org/
COMMENT=	Cartographic projection software
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

PREV_PKGPATH=		misc/proj

USE_LANGUAGES=		c99 c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

# \todo Debug this.
# Tests fail if proj relies on NetBSD 8's C99 math, vs proj's
# replacement functions.
.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DHAVE_C99_MATH=0
.endif

CXXFLAGS.SunOS+=	-fpermissive

TEST_TARGET=		check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
