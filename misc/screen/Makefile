# $NetBSD: Makefile,v 1.24 2001/02/17 18:09:23 wiz Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=	screen-3.9.8
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager

GNU_CONFIGURE=	yes
INFO_FILES=	screen.info
PLIST_SUBST=	DISTNAME=${DISTNAME}

post-install:
	@${MKDIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc

.include "../../mk/bsd.pkg.mk"
