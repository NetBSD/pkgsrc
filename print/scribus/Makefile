# $NetBSD: Makefile,v 1.16 2004/05/08 20:11:27 reed Exp $

DISTNAME=	scribus-1.1.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://scribus.planetmirror.com/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://web2.altmuehlnet.de/fschmid/
COMMENT=	Publishing layout with graphical interface

USE_BUILDLINK3=		yes
USE_X11=		# defined
USE_GNU_TOOLS+=		make
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=        --with-qt-dir=${QTDIR} \
			--with-extra-libs=${LOCALBASE}/lib \
			--with-extra-includes=${LOCALBASE}/include

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
