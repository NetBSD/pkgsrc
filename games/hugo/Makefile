# $NetBSD: Makefile,v 1.5 2005/05/07 23:04:17 dillo Exp $
#

DISTNAME=	hugov31_unix_source
PKGNAME=	hugo-3.1.02
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/hugo/source/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hugolib.zip

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.generalcoffee.com/hugo.html
COMMENT=	Interactive fiction design system and interpreter

SITES_hugolib.zip=${MASTER_SITE_IFARCHIVE:=programming/hugo/library/}

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_GNU_TOOLS+=	make
# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6 NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*
WRKSRC=		${WRKDIR}/hugov3.1.02

LIBDIR=		${PREFIX}/share/hugo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/he ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${LIBDIR}
	for f in hugofix.g hugofix.h hugolib.h objlib.h resource.h \
		system.h verblib.g verblib.h verbstub.g verbstub.h window.h; \
	do \
		${INSTALL_DATA} ${WRKDIR}/$$f ${LIBDIR}; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
