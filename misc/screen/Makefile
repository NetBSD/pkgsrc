# $NetBSD: Makefile,v 1.19 1999/08/13 10:43:14 agc Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=       screen-3.9.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@netbsd.org

GNU_CONFIGURE=	yes
INFO_FILES=	screen.info

PLIST_SRC=	${WRKDIR}/PLIST-src

post-install:
	@${MKDIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc
	${SED} -e 's|\$${DISTNAME}|${DISTNAME}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
