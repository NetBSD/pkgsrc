# $NetBSD: Makefile,v 1.2 2000/01/15 18:46:23 jlam Exp $
#

DISTNAME=	emixer-0.05.3
PKGNAME=	emixer-0.5.3
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/

DEPENDS+=	libslang-1.*:../../devel/libslang
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	mpg123-0.59*:../../audio/mpg123

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
