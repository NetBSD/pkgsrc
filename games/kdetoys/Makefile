# $NetBSD: Makefile,v 1.12 2001/09/27 23:18:07 jlam Exp $

DISTNAME=	kdetoys-1.1.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Toys for the KDE integrated X11 desktop

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

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
