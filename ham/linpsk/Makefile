# $NetBSD: Makefile,v 1.1.1.1 2005/01/23 20:32:41 wulf Exp $
#

DISTNAME=	linpsk-0.8.0.4
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linpsk/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://linpsk.sourceforge.net/
COMMENT=	PSK31 terminal program using QT3

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
USE_GNUMAKE=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

LDFLAGS+= ${LIBOSSAUDIO} -lqt-mt

CONFIGURE_ARGS+="--with-fftw-dir=${LOCALBASE}"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
