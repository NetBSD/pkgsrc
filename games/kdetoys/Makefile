# $NetBSD: Makefile,v 1.13 2002/03/13 17:37:01 fredb Exp $

DISTNAME=	kdetoys-1.1.2
PKGREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Toys for the KDE integrated X11 desktop

DEPENDS+=	kdebase-1.1.2nb1:../../x11/kdebase

CONFLICTS=	kworldwatch-[0-9]*

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	"--datadir=${KDEBASEDIR}/share/kde" \
		"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${KDEBASEDIR} \
		QTDIR=${QT1DIR}/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${X11BASE}/lib -Wl,-R${X11BASE}/lib -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
