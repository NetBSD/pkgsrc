# $NetBSD: Makefile,v 1.13 2012/10/06 11:54:43 asau Exp $
#

DISTNAME=	hugov31_unix_source
PKGNAME=	hugo-3.1.02.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/hugo/source/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hugolib.zip

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.generalcoffee.com/hugo.html
COMMENT=	Interactive fiction design system and interpreter

SITES.hugolib.zip=${MASTER_SITE_IFARCHIVE:=programming/hugo/library/}

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_TOOLS+=	gmake
# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]*-* NetBSD-1.5*-* NetBSD-1.6-*
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6[A-L]*-*
WRKSRC=		${WRKDIR}/hugov3.1.02

LIBDIR=		${PREFIX}/share/hugo

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/he ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${LIBDIR}
	for f in hugofix.g hugofix.h hugolib.h objlib.h resource.h \
		system.h verblib.g verblib.h verbstub.g verbstub.h window.h; \
	do \
		${INSTALL_DATA} ${WRKDIR}/$$f ${DESTDIR}${LIBDIR}; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
