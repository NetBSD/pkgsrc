# $NetBSD: Makefile,v 1.29.2.1 2003/02/17 15:45:21 agc Exp $
#

DISTNAME=	avifile-0.6.20010814
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://avifile.sourceforge.net/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs

WRKSRC=		${WRKDIR}/avifile-0.6

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_SRC_ON_FTP=		"Already in MASTER_SITE_LOCAL"

BUILD_USES_GETTEXT_M4=	YES

AUTOMAKE_REQD=		1.4
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-win32-path=${LOCALBASE}/lib/win32
CONFIGURE_ARGS+=	--disable-dpms

# ffmpeg codec *partially* works, but is incredibly slow so we don't want
# to use it
CONFIGURE_ARGS+=	--disable-ffmpeg

CXXFLAGS+=		-L${LOCALBASE}/lib -I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

AVIFILE_USE_QT?=	NO

.if defined (AVIFILE_USE_QT) && ${AVIFILE_USE_QT} == "YES"
#
# it would be more logical to set PLIST_SRC to PLIST first and then add
# PLIST.qt to it, but @dirrm lib/avifile-0.6 will fail while processing
# pkg/PLIST, because the directory still contains files (they are listed in
# PLIST.qt) and isn't empty, thus can't be removed
#
PLIST_SRC=		${PKGDIR}/PLIST.qt
PLIST_SRC+=		${PKGDIR}/PLIST

CXXFLAGS+=		-Wl,-R${QTDIR}/lib
CXXFLAGS+=		-Wl,-R${LOCALBASE}/lib
CXXFLAGS+=		-Wl,-R${X11BASE}/lib

CONFIGURE_ARGS+=	--enable-qt
CONFIGURE_ARGS+=	--with-qt-dir="${QTDIR}"

.  include "../../x11/qt2-designer/buildlink2.mk"
.endif

pre-configure:
	cd ${WRKSRC} && libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOCONF}
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing --copy --foreign

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
