# $NetBSD: Makefile,v 1.12 2001/02/13 21:45:06 tron Exp $

DISTNAME=	fxtv-1.03
CATEGORIES=	graphics
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://people.freebsd.org/~rhh/fxtv/

DEPENDS+=	tiff>=3.5.5:../../graphics/tiff

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

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
