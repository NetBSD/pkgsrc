# $NetBSD: Makefile,v 1.16 1999/08/10 09:18:01 agc Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=       screen-3.9.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@netbsd.org

GNU_CONFIGURE=	yes
INFO_FILES=	screen.info

post-install:
	@${MKDIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc

.include "../../mk/bsd.pkg.mk"
