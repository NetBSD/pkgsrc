# $NetBSD: Makefile,v 1.20 1998/09/27 18:07:21 tron Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/28 00:04:18 se Exp
#

DISTNAME=	kdeutils-1.0
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	qt-1.40:../../x11/qt
DEPENDS+=	kdelibs-1.0:../../x11/kdelibs
DEPENDS+=	kdebase-1.0:../../x11/kdebase

CONFLICTS=	kdeutils-2.1b kdeutils-3.1b kdeutils-4.1b

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL="/usr/bin/install"

.include "../../mk/bsd.pkg.mk"
