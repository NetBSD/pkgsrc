# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:02 tv Exp $

DISTNAME=	fxtv-1.03
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~rhh/fxtv/
COMMENT=	TV display application for Brooktree 848 compatible TV cards

#ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-arm NetBSD-1.[5-9]*-arm32	\
#			NetBSD-1.[5-9]*-atari NetBSD-1.[5-9]*-i386

USE_BUILDLINK3=	YES
USE_X11BASE=	YES
USE_GNU_TOOLS+=	make
XAW_TYPE?=	3d

SUBST_CLASSES+=		ossaudio
SUBST_MESSAGE.ossaudio=	"Fixing path to audio device."
SUBST_STAGE.ossaudio=	pre-configure
SUBST_FILES.ossaudio=	app_rsrc.h
SUBST_FILES.ossaudio+=	Fxtv
SUBST_SED.ossaudio=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

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
	if [ -r /usr/include/machine/mouse.h ] ; then \
		echo '#define HAVE_MOUSE_H 1' > ${WRKSRC}/netbsdconf.h; \
	else \
		echo '#define HAVE_MOUSE_H 0' > ${WRKSRC}/netbsdconf.h; \
	fi

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
