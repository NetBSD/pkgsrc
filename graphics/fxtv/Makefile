# $NetBSD: Makefile,v 1.16 2001/08/23 19:19:40 jlam Exp $

DISTNAME=	fxtv-1.03
CATEGORIES=	graphics
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://people.freebsd.org/~rhh/fxtv/
COMMENT=	TV display application for Brooktree 848 compatible TV cards

ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-arm32 NetBSD-1.[5-9]*-atari \
			NetBSD-1.[5-9]*-i386

USE_X11BASE=	YES
USE_GMAKE=	YES
XAW_TYPE?=	3d

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	X11PREFIX=${X11PREFIX}

# The purpose of this check is to make sure that there is a "Xaw3d"
# compatible widget set installed because normal "Xaw" won't work.
#
.if (${XAW_TYPE} == standard)
XAW_TYPE=	3d
.endif

post-extract:
	@${RM} -f ${WRKSRC}/videolib/videolib.o

.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
