# $NetBSD: Makefile,v 1.9 2001/06/19 15:57:39 jlam Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/
COMMENT=	mpg123-frontend that can mix two mp3 streams, and fade between them

DEPENDS+=	mpg123-0.59*:../../audio/mpg123

#USE_CURSES=		YES
USE_BUILDLINK_ONLY=	YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
