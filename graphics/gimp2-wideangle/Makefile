# $NetBSD: Makefile,v 1.39.2.1 2012/10/03 12:08:02 spz Exp $
#

DISTNAME=	wideangle
PKGNAME=	gimp2-wideangle-1.0
PKGREVISION=	29
CATEGORIES=	graphics
MASTER_SITES=	http://members.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.ozemail.com.au/~hodsond/wideangle.html
COMMENT=	GIMP plugin for wideangle lens distortions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}

LINK_PTHREAD=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
LINK_PTHREAD+=	-lm    # Tack on, explicit for binutils 2.22 linker

do-build:
	(cd ${WRKSRC} && LIBS=${LINK_PTHREAD:Q} gimptool-2.0 --build wideangle.c)

do-install:
	plugindir=`gimptool-2.0 --gimpplugindir` && \
	${INSTALL_DATA_DIR} ${DESTDIR}$${plugindir}/plug-ins && \
	${INSTALL_PROGRAM} ${WRKSRC}/wideangle ${DESTDIR}$${plugindir}/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
