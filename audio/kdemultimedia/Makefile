# $NetBSD: Makefile,v 1.19 2003/12/26 19:56:40 wiz Exp $

DISTNAME=	kdemultimedia-1.1.2
PKGREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	KDE audio tools

DEPENDS+=	kdebase-1.1.2nb4:../../x11/kdebase

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	"--datadir=${KDEBASEDIR}/share/kde" \
		"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${KDEBASEDIR} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

KDE_LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
KDE_LDFLAGS+=	-Wl,${RPATH_FLAG}${LOCALBASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib
FIX_RPATH+=	KDE_LDFLAGS

post-install:
	@${CHMOD} -R go-w ${KDEBASEDIR}/share/kde/apps/kscd/cddb

.include "../../mk/bsd.pkg.mk"
