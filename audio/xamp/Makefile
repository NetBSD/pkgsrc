# $NetBSD: Makefile,v 1.5 2000/07/11 14:53:37 agc Exp $
# FreeBSD: ports/audio/xamp/Makefile,v 1.5 1999/08/25 04:36:22 obrien Exp
#

DISTNAME=	xamp-0.8-7
PKGNAME=	xamp-0.8.7
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.simcb.ru/pub/unix/x11/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://edu.lahti.fi/xamp/

DEPENDS+=	qt1-1.44:../../x11/qt1

WRKSRC=		${WRKDIR}/xamp-0.8/xamp-0.8
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS}"
USE_GMAKE=	yes
USE_X11BASE=	yes

CONFIGURE_ARGS+=	"--with-qt-dir=`${MAKE} show-qt1-prefix`/qt1"

CONFIGURE_ENV+=	"QTDIR=`${MAKE} show-qt1-prefix`/qt1"
CONFIGURE_ENV+=	"MOC=`${MAKE} show-qt1-prefix`/qt1/bin/moc"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xamp ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/xamp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
