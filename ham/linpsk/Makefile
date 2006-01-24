# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:18 wiz Exp $
#

DISTNAME=	linpsk-0.8.1
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linpsk/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://linpsk.sourceforge.net/
COMMENT=	PSK31 terminal program using QT3

BUILD_DEPENDS+=	qt3-tools-3.*:../../x11/qt3-tools

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_GNUMAKE=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

LDFLAGS+= ${LIBOSSAUDIO} -lqt-mt

CONFIGURE_ARGS+="--with-fftw-dir=${LOCALBASE}"

post-configure:
	${_PKG_DEBUG}${_PKG_SILENT}${LN} -s ${FILESDIR}/pkgsrc_fixes.h ${BUILDLINK_DIR}/include/

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
