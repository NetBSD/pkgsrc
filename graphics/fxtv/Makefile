# $NetBSD: Makefile,v 1.24 2003/09/28 15:58:34 jmmv Exp $

DISTNAME=	fxtv-1.03
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~rhh/fxtv/
COMMENT=	TV display application for Brooktree 848 compatible TV cards

#ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-arm NetBSD-1.[5-9]*-arm32	\
#			NetBSD-1.[5-9]*-atari NetBSD-1.[5-9]*-i386

USE_BUILDLINK2=	YES
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

pre-configure:
	cd ${WRKSRC}; for file in app_rsrc.h Fxtv; do			\
		${SED}	-e "s,/dev/dsp,${DEVOSSAUDIO},g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	if [ -e /usr/include/machine/mouse.h ] ; then \
		echo '#define HAVE_MOUSE_H 1' > ${WRKSRC}/netbsdconf.h; \
	else \
		echo '#define HAVE_MOUSE_H 0' > ${WRKSRC}/netbsdconf.h; \
	fi

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
