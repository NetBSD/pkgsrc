# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:45 tv Exp $
#

DISTNAME=	hugov30_unix_source
PKGNAME=	hugo-3.0.07
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ifarchive.org/if-archive/programming/hugo/source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hugolib.zip

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://161.184.245.22/tessman/gcc/hugo.html
COMMENT=	Interactive fiction design system and interpreter

SITES_hugolib.zip=http://www.ifarchive.org/if-archive/programming/hugo/library/

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6 NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*
WRKSRC=		${WRKDIR}/hugov3.0.07

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
