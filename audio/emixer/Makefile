# $NetBSD: Makefile,v 1.4 2000/04/16 02:57:20 mycroft Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/

DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	mpg123-0.59*:../../audio/mpg123

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
