# $NetBSD: Makefile,v 1.5 2001/06/25 14:09:45 zuntum Exp $
#

DISTNAME=	avifile-0.6.20010618
CATEGORIES=	graphics
MASTER_SITES=	http://flis.utech.lublin.pl/~zuntum/distfiles/		\
		http://zuntum.net/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
DEPENDS+=	SDL>=1.1.2:../../devel/SDL
DEPENDS+=	automake-*:../../devel/automake

WITH_QT?=	NO

.if defined (WITH_QT) && ${WITH_QT} == YES
PLIST_SUBST+=	QT=''
.else
PLIST_SUBST+=	QT='@comment '
.endif

WRKSRC=		${WRKDIR}/avifile-0.6

ONLY_FOR_PLATFORM= NetBSD-*-i386

USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	SDL_CONFIG="${LOCALBASE}/bin/sdl-config"

CXXFLAGS+=	-L${BUILDLINK_DIR}/lib -I${BUILDLINK_DIR}/include

CONFIGURE_ARGS+=--with-win32-path=${LOCALBASE}/lib/win32		\
		--enable-sdl						\
		--enable-release					\
		--disable-dpms

.if defined (WITH_QT) && ${WITH_QT} == YES
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../x11/qt2-designer/buildlink.mk"
BUILDLINK_QTDIR=	${BUILDLINK_DIR}/qt2
QTDIR=			${X11PREFIX}/qt2

CXXFLAGS+=	-Wl,-R${QTDIR}/lib
CXXFLAGS+=	-Wl,-R${LOCALBASE}/lib
CXXFLAGS+=	-Wl,-R${X11BASE}/lib

CONFIGURE_ARGS+=--enable-qt
CONFIGURE_ARGS+=--with-qt-dir="${BUILDLINK_DIR}/qt2"

CONFIGURE_ENV+=	QTDIR="${BUILDLINK_DIR}/qt2"
CONFIGURE_ENV+=	MOC="${BUILDLINK_QTDIR}/bin/moc"
CONFIGURE_ENV+=	UIC="${BUILDLINK_QTDIR}/bin/uic"
.endif

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
