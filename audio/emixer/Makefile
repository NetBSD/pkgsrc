# $NetBSD: Makefile,v 1.8 2001/02/16 13:30:35 wiz Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/
COMMENT=	mpg123-frontend that can mix two mp3 streams, and fade between them

DEPENDS+=	mpg123-0.59*:../../audio/mpg123

USE_CURSES=	YES
REPLACE_NCURSES=${WRKSRC}/nctgui.h
MAKE_ENV+=	NEED_NCURSES="${NEED_NCURSES}"

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
