# $NetBSD: Makefile,v 1.8 1998/04/20 11:56:29 frueauf Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=	kdenetwork-Beta3-1
PKGNAME=	kdenetwork-3.1b
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt \
		${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	qt.1.3[0-9]:${PORTSDIR}/x11/qt \
		gif.[23].:${PORTSDIR}/graphics/giflib \
		jpeg.[67].:${PORTSDIR}/graphics/jpeg \
		mimelib.1.:${PORTSDIR}/converters/kdesupport \
		uu.1.:${PORTSDIR}/converters/uulib \
		kdecore.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kfm.0.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool.0.9[0-9]:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kappfinder:${PORTSDIR}/x11/kdebase

USE_X11=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--prefix=${PREFIX}" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

WRKSRC=		${WRKDIR}/kdenetwork

.include "../../mk/bsd.pkg.mk"
