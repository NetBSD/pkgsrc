# $NetBSD: Makefile,v 1.19 2004/10/03 00:18:06 tv Exp $

DISTNAME=	scribus-1.1.7
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://scribus.planetmirror.com/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scribus.net/
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
