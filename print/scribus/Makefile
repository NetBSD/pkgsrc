# $NetBSD: Makefile,v 1.2 2002/07/10 10:13:56 agc Exp $

DISTNAME=	scribus-0.7.5
CATEGORIES=	print
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://web2.altmuehlnet.de/fschmid/
COMMENT=	Publishing layout with graphical interface

USE_PTHREAD=    native pth-syscall

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

EVAL_PREFIX+=		QT3DIR=qt3
CONFIGURE_ARGS+=        --with-qt-dir=${BUILDLINK_QTDIR} \
			--with-extra-libs=${BUILDLINK_DIR}/lib \
			--with-extra-includes=${BUILDLINK_DIR}/include

CONFIGURE_ENV+=		all_libraries="-Wl,-R${QT3DIR}/qt3/lib -L${BUILDLINK_DIR}/lib -Wl,-R${LOCALBASE}/lib -L${BUILDLINK_X11_DIR}/lib -Wl,-R${X11BASE}/lib -ljpeg"

.include "../../x11/qt3-libs/buildlink.mk"
.include "../../x11/qt3-tools/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
