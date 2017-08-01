# $NetBSD: Makefile,v 1.34 2017/08/01 16:47:35 wiz Exp $
#

DISTNAME=	emixer-0.05.5
PKGNAME=	emixer-0.5.5
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	# http://emixer.linuxbox.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://toaster.muc-t-systems.com/~emixer/
COMMENT=	Frontend for mpg123 that can mix two mp3 streams and fade between them

DEPENDS+=	mpg123-1.*:../../audio/mpg123

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin share/doc

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
