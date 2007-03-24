# $NetBSD: Makefile,v 1.25 2007/03/24 19:21:18 joerg Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://emixer.linuxbox.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toaster.muc-t-systems.com/~emixer/
COMMENT=	mpg123-frontend that can mix two mp3 streams, and fade between them

DEPENDS+=	mpg123{,-esound,-nas}-0.59*:../../audio/mpg123

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin share/doc

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
