# $NetBSD: Makefile,v 1.9 2001/07/26 15:20:49 zuntum Exp $
#

DISTNAME=	avifile-0.6.20010726
CATEGORIES=	graphics
MASTER_SITES=	http://flis.utech.lublin.pl/~zuntum/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
DEPENDS+=	automake-*:../../devel/automake

WITH_QT?=	NO

.if defined (WITH_QT) && ${WITH_QT} == YES
PLIST_SUBST+=	QT=''
.else
PLIST_SUBST+=	QT='@comment '
.endif

WRKSRC=		${WRKDIR}/avifile-0.6

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES

CXXFLAGS+=		-L${BUILDLINK_DIR}/lib -I${BUILDLINK_DIR}/include -I${X11PREFIX}/include

CONFIGURE_ARGS+=	--with-win32-path=${LOCALBASE}/lib/win32
CONFIGURE_ARGS+=	--disable-dpms
CONFIGURE_ARGS+=	--disable-ffmpeg

.if defined (WITH_QT) && ${WITH_QT} == YES
.include "../../x11/qt2-designer/buildlink.mk"
CXXFLAGS+=		-Wl,-R${QTDIR}/lib
CXXFLAGS+=		-Wl,-R${LOCALBASE}/lib
CXXFLAGS+=		-Wl,-R${X11BASE}/lib

CONFIGURE_ARGS+=	--enable-qt
CONFIGURE_ARGS+=	--with-qt-dir="${BUILDLINK_DIR}/qt2"
.endif

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
