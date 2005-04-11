# $NetBSD: Makefile,v 1.22 2005/04/11 21:44:52 tv Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://toaster.muc-t-systems.com/~emixer/
COMMENT=	mpg123-frontend that can mix two mp3 streams, and fade between them

DEPENDS+=	mpg123{,-esound,-nas}-0.59*:../../audio/mpg123

NO_CONFIGURE=	YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
