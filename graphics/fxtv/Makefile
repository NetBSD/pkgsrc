# $NetBSD: Makefile,v 1.14 2001/05/10 22:54:12 tron Exp $

DISTNAME=	fxtv-1.03
CATEGORIES=	graphics
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://people.freebsd.org/~rhh/fxtv/
COMMENT=	TV display application for Brooktree 848 compatible TV cards

DEPENDS+=	tiff>=3.5.5:../../graphics/tiff

ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-arm32 NetBSD-1.[5-9]*-atari \
			NetBSD-1.[5-9]*-i386

USE_X11BASE=	YES
USE_XAW=	YES
USE_XPM=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	X11PREFIX=${X11PREFIX}

XAW_TYPE?=	3d

# The purpose of this check is to make sure that there is a "Xaw3d"
# compatible widget set installed because normal "Xaw" won't work.

.if (${XAW_TYPE} == standard)
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
.endif

post-extract:
	@${RM} -f ${WRKSRC}/videolib/videolib.o

.include "../../mk/bsd.pkg.mk"
