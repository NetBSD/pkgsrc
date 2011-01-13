# $NetBSD: Makefile,v 1.20 2011/01/13 13:38:26 wiz Exp $
#

DISTNAME=	linpsk-0.8.1
PKGREVISION=	7
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linpsk/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://linpsk.sourceforge.net/
COMMENT=	PSK31 terminal program using QT3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	qt3-tools-3.*:../../x11/qt3-tools

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

LDFLAGS+= ${LIBOSSAUDIO} -lqt-mt ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

CONFIGURE_ARGS+="--with-fftw-dir=${LOCALBASE}"

post-configure:
	${LN} -s ${FILESDIR}/pkgsrc_fixes.h ${BUILDLINK_DIR}/include/

.include "../../mk/oss.buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
