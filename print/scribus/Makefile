# $NetBSD: Makefile,v 1.11 2003/10/29 20:54:51 reed Exp $

DISTNAME=	scribus-1.1.1
CATEGORIES=	print
MASTER_SITES=	http://ftp.kde.com/Office/Text_Word_Processing/Scribus/ \
		http://web2.altmuehlnet.de/fschmid/ \
		http://scribus.planetmirror.com/ \
		ftp://ftp.ntua.gr/pub/gnu/scribus/ \
		http://scribus.ipc.one.pl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://web2.altmuehlnet.de/fschmid/
COMMENT=	Publishing layout with graphical interface

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=        --with-qt-dir=${QTDIR} \
			--with-extra-libs=${LOCALBASE}/lib \
			--with-extra-includes=${LOCALBASE}/include

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
