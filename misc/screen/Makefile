# $NetBSD: Makefile,v 1.15 1999/04/25 23:38:12 tv Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=       screen-3.7.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=screen/} \
		ftp://ftp.uni-erlangen.de/pub/utilities/screen/

MAINTAINER=	hubertf@netbsd.org

GNU_CONFIGURE=	yes
INFO_FILES=	screen.info

post-install:
	@${MKDIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc

.include "../../mk/bsd.pkg.mk"
