# $NetBSD: Makefile,v 1.12 2001/01/05 01:40:39 wiz Exp $
#

DISTNAME=	kdf-0.5.1
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.edu.uni-klu.ac.at/~mkropfbe

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	kde-1.1.2:../../x11/kde

USE_LIBINTL=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	KDEBASEDIR=kdebase QT1DIR=qt1
CONFIGURE_ARGS+=--datadir=${KDEBASEDIR}/share/kde \
		--with-qt-dir=${QT1DIR}/qt1 \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${KDEBASEDIR} \
		QTDIR=${QT1DIR}/qt1 \
		MOC=${QT1DIR}/qt1/bin/moc \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
