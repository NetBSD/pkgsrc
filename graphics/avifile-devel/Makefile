# $NetBSD: Makefile,v 1.1.1.1 2001/06/16 11:48:04 zuntum Exp $
#

DISTNAME=	avifile-0.6.20010616
CATEGORIES=	graphics
MASTER_SITES=	http://flis.utech.lublin.pl/~zuntum/distfiles/		\
		http://zuntum.net/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
DEPENDS+=	SDL>=1.1.2:../../devel/SDL
DEPENDS+=	pth>=1.3.7:../../devel/pth
DEPENDS+=	automake-*:../../devel/automake

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config

WITH_QT?=	NO

.if defined (WITH_QT) && ${WITH_QT} == YES
DEPENDS+=	qt2-libs>=2.1.0:../../x11/qt2-libs
PLIST_SUBST+=	QT=''
.else
PLIST_SUBST+=	QT='@comment '
.endif

WRKSRC=		${WRKDIR}/avifile-0.6

ONLY_FOR_PLATFORM= NetBSD-*-i386
USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}"				\
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"	\
		CXXFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"	\
		LIBS="-L${X11BASE}/lib -Wl,-R${X11BASE}/lib		\
		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

CONFIGURE_ARGS+=--with-win32-path=${LOCALBASE}/lib/win32		\
		--enable-sdl						\
		--enable-release					\
		--disable-dpms

.if defined (WITH_QT) && ${WITH_QT} == YES
CONFIGURE_ARGS+=--enable-qt						\
		--with-qt-dir=${X11BASE}/qt2				\
		--with-qt-includes=${X11BASE}/qt2/include		\
		--with-qt-libraries=${X11BASE}/qt2/lib

MOC?=		${X11BASE}/qt2/bin/moc
UIC?=		${X11BASE}/qt2/bin/uic

CONFIGURE_ENV+=	MOC="${MOC}"						\
		UIC="${UIC}"						\
		LIBS+="-L${X11BASE}/qt2/lib -Wl,-R${X11BASE}/qt2/lib"
.endif

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../mk/bsd.pkg.mk"
