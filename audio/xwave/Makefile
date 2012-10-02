# $NetBSD: Makefile,v 1.27 2012/10/02 23:48:16 asau Exp $
#

DISTNAME=		xwave2
PKGNAME=		xwave-2.0
PKGREVISION=		2
CATEGORIES=		audio x11
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Audio player/recorder/editor for the X Window System

USE_IMAKE=		YES
INSTALLATION_DIRS=	bin lib/X11/app-defaults

MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		devaudio
SUBST_STAGE.devaudio=	pre-configure
SUBST_FILES.devaudio=	src/XWave
SUBST_SED.devaudio=	-e 's,/dev/audio,${DEVOSSAUDIO},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwave ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/XWave \
		${DESTDIR}${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xwave2
	${INSTALL_DATA} ${WRKSRC}/README \
			${WRKSRC}/README-XWAVE2 \
			${WRKSRC}/README.v06 \
			${WRKSRC}/COPYING \
			${WRKSRC}/INSTALL \
			${DESTDIR}${PREFIX}/share/doc/xwave2

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
