# $NetBSD: Makefile,v 1.7 2001/01/07 03:10:50 wiz Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/

DEPENDS+=	mpg123-0.59*:../../audio/mpg123

USE_CURSES=	YES
REPLACE_NCURSES=${WRKSRC}/nctgui.h
MAKE_ENV+=	NEED_NCURSES="${NEED_NCURSES}"

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
