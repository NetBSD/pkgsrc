# New ports collection makefile for:   kdenetwork
# Version required:    Beta2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $NetBSD: Makefile,v 1.5 1998/02/23 23:36:46 tron Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=	kdenetwork-Beta2-1
PKGNAME=	kdenetwork-2.1b
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta2/distribution/tgz/source/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt \
		${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	qt.1.3[0-9]:${PORTSDIR}/x11/qt \
		gif.[23].:${PORTSDIR}/graphics/giflib \
		jpeg.[67].:${PORTSDIR}/graphics/jpeg \
		mimelib.1.:${PORTSDIR}/converters/kdesupport \
		uulib.0.:${PORTSDIR}/converters/kdesupport \
		kdecore.0.1[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui.0.1[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript.0.[1-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw.0.1[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm.0.[1-9]:${PORTSDIR}/x11/kdelibs \
		mediatool.0.[6-9]:${PORTSDIR}/x11/kdelibs

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${X11BASE}/include -I${PREFIX}/include -I${PREFIX}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${PREFIX}/lib" \
		"--prefix=${PREFIX}" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${X11BASE}/include/qt"

WRKSRC=		${WRKDIR}/kdenetwork

.include <bsd.port.mk>
