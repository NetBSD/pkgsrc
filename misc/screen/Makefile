# $NetBSD: Makefile,v 1.22 2000/09/01 14:39:51 wiz Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=	screen-3.9.5
PKGNAME=	screen-3.9.5nb1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html

GNU_CONFIGURE=	yes
INFO_FILES=	screen.info
PLIST_SUBST=	DISTNAME=${DISTNAME}

post-install:
	@${MKDIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc

.include "../../mk/bsd.pkg.mk"
