# $NetBSD: Makefile,v 1.3 2000/02/02 03:39:59 hubertf Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
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
