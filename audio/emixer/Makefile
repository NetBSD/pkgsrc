# $NetBSD: Makefile,v 1.6 2000/06/12 20:52:55 dmcmahill Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/

DEPENDS+=	mpg123-0.59*:../../audio/mpg123
DEPENDS+=	ncurses>=4.2:../../devel/ncurses

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
