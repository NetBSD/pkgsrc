# $NetBSD: Makefile,v 1.26 2010/02/03 23:19:10 joerg Exp $
#

DISTNAME=	wideangle
PKGNAME=	gimp2-wideangle-1.0
PKGREVISION=	16
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

do-build:
	(cd ${WRKSRC} && LIBS=${LINK_PTHREAD:Q} gimptool-2.0 --build wideangle.c)

do-install:
	plugindir=`gimptool-2.0 --gimpplugindir` && \
	${INSTALL_DATA_DIR} ${DESTDIR}$${plugindir}/plug-ins && \
	${INSTALL_PROGRAM} ${WRKSRC}/wideangle ${DESTDIR}$${plugindir}/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
