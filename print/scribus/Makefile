# $NetBSD: Makefile,v 1.5 2002/10/05 12:06:15 jlam Exp $

DISTNAME=	scribus-0.7.5
CATEGORIES=	print
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://web2.altmuehlnet.de/fschmid/
COMMENT=	Publishing layout with graphical interface

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=        --with-qt-dir=${QTDIR} \
			--with-extra-libs=${LOCALBASE}/lib \
			--with-extra-includes=${LOCALBASE}/include

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
