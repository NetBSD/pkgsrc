# $NetBSD: Makefile,v 1.23 2001/11/29 01:12:34 hubertf Exp $
#

DISTNAME=	avifile-0.6.20010814
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://zuntum.utech.lublin.pl/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

WRKSRC=		${WRKDIR}/avifile-0.6

ONLY_FOR_PLATFORM=	NetBSD-*-i386

BUILD_USES_GETTEXT_M4=	YES

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES

CXXFLAGS+=		-L${BUILDLINK_DIR}/lib -I${BUILDLINK_DIR}/include

CONFIGURE_ARGS+=	--with-win32-path=${LOCALBASE}/lib/win32
CONFIGURE_ARGS+=	--disable-dpms
# ffmpeg codec *partially* works, but is incredibly slow so we don't want to use it
CONFIGURE_ARGS+=	--disable-ffmpeg

.include "../../mk/bsd.prefs.mk"

AVIFILE_USE_QT?=	NO

.if defined (AVIFILE_USE_QT) && ${AVIFILE_USE_QT} == "YES"

# it would be more logical to set PLIST_SRC to PLIST first and then add PLIST.qt to it,
# but @dirrm lib/avifile-0.6 will fail while processing pkg/PLIST,
# because the directory still contains files (they are listed in PLIST.qt) and isn't empty,
# thus can't be removed
PLIST_SRC=		${PKGDIR}/PLIST.qt
PLIST_SRC+=		${PKGDIR}/PLIST

CXXFLAGS+=		-Wl,-R${QTDIR}/lib
CXXFLAGS+=		-Wl,-R${LOCALBASE}/lib
CXXFLAGS+=		-Wl,-R${X11BASE}/lib

CONFIGURE_ARGS+=	--enable-qt
CONFIGURE_ARGS+=	--with-qt-dir="${BUILDLINK_DIR}/qt2"

.include "../../x11/qt2-designer/buildlink.mk"

.endif

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
