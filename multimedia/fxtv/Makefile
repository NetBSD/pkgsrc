# $NetBSD: Makefile,v 1.7 2005/02/23 01:11:47 wiz Exp $

DISTNAME=	fxtv-1.03
PKGREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~rhh/fxtv/
COMMENT=	TV display application for Brooktree 848 compatible TV cards

USE_BUILDLINK3=	YES
USE_X11BASE=	YES
USE_GNU_TOOLS+=	make
XAW_TYPE?=	3d

SUBST_CLASSES+=		ossaudio
SUBST_MESSAGE.ossaudio=	"Fixing path to audio device."
SUBST_STAGE.ossaudio=	pre-configure
SUBST_FILES.ossaudio=	app_rsrc.h Fxtv README
SUBST_SED.ossaudio=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

.include "../../mk/bsd.prefs.mk"

# The purpose of this check is to make sure that there is a "Xaw3d"
# compatible widget set installed because normal "Xaw" won't work.
#
.if (${XAW_TYPE} == standard)
XAW_TYPE=	3d
.endif

post-extract:
	@${RM} -f ${WRKSRC}/videolib/videolib.o

pre-configure:
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
