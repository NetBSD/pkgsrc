# $NetBSD: Makefile,v 1.18 2017/01/03 21:42:55 roy Exp $
#

DISTNAME=	hugov31_unix_source
PKGNAME=	hugo-3.1.02.1
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/hugo/source/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hugolib.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.generalcoffee.com/hugo.html
COMMENT=	Interactive fiction design system and interpreter

SITES.hugolib.zip=${MASTER_SITE_IFARCHIVE:=programming/hugo/library/}

USE_TOOLS+=	gmake
FAKE_NCURSES=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
