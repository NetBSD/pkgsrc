# $NetBSD: Makefile,v 1.42 2023/10/21 17:11:06 gdt Exp $

DISTNAME=	fxtv-1.03
PKGREVISION=	25
CATEGORIES=	multimedia
MASTER_SITES=	${HOMEPAGE:Q}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.freebsd.org/~rhh/fxtv/
COMMENT=	Composite video viewer for Brooktree 848 compatible TV cards

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	${PKGMANDIR}/man1

SUBST_CLASSES+=		ossaudio
SUBST_MESSAGE.ossaudio=	Fixing path to audio device.
SUBST_STAGE.ossaudio=	pre-configure
SUBST_FILES.ossaudio=	app_rsrc.h Fxtv README
SUBST_SED.ossaudio=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

post-extract:
	${RM} -f ${WRKSRC}/videolib/videolib.o

pre-configure:
	set -e; if [ -r /usr/include/machine/mouse.h ] ; then \
		${ECHO} '#define HAVE_MOUSE_H 1' > ${WRKSRC}/netbsdconf.h; \
	else \
		${ECHO} '#define HAVE_MOUSE_H 0' > ${WRKSRC}/netbsdconf.h; \
	fi

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
