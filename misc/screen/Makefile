# $NetBSD: Makefile,v 1.9 1998/04/22 11:05:03 agc Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=       screen-3.7.4
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU}

MAINTAINER=	hubertf@netbsd.org

GNU_CONFIGURE=	yes
MAN1=		screen.1
INFO_FILES=	screen.info

post-install:
	@${MKDIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc

.include "../../mk/bsd.pkg.mk"
