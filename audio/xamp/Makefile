# $NetBSD: Makefile,v 1.1.1.1 1999/09/17 00:48:26 hubertf Exp $
# FreeBSD: ports/audio/xamp/Makefile,v 1.5 1999/08/25 04:36:22 obrien Exp
#

DISTNAME=	xamp-0.8-7
PKGNAME=	xamp-0.8.7
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.simcb.ru/pub/unix/x11/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://edu.lahti.fi/xamp/

DEPENDS+=	qt-1.44:../../x11/qt

WRKSRC=		${WRKDIR}/xamp-0.8/xamp-0.8
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
USE_GMAKE=	yes
USE_X11BASE=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xamp ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/xamp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
