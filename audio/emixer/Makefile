# $NetBSD: Makefile,v 1.1.1.1 1999/12/13 02:48:41 hubertf Exp $
#

DISTNAME=	emixer-0.05.3
PKGNAME=	emixer-0.5.3
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://emixer.linuxbox.com/

DEPENDS+=	libslang-1.*:../../devel/libslang
DEPENDS+=	ncurses-4.*:../../devel/ncurses
DEPENDS+=	mpg123-0.59*:../../audio/mpg123

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
