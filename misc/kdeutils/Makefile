# New ports collection makefile for:   kdeutils
# Version required:    Beta3
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $NetBSD: Makefile,v 1.6 1998/03/21 01:54:30 tron Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/28 00:04:18 se Exp
#

DISTNAME=	kdeutils-Beta3-1
PKGNAME=	kdeutils-3.1b
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt.1.3[0-9]:${PORTSDIR}/x11/qt \
		gif.[23].:${PORTSDIR}/graphics/giflib \
		jpeg.[67].:${PORTSDIR}/graphics/jpeg \
		kdecore.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kfm.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool.0.9[0-9]:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kappfinder:${PORTSDIR}/x11/kdebase

USE_X11=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${PREFX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${X11BASE}/include/qt"
CONFIGURE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

WRKSRC=		${WRKDIR}/kdeutils

.include <bsd.port.mk>
