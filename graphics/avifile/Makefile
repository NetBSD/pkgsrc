# $NetBSD: Makefile,v 1.1.1.1 2001/04/12 21:26:21 zuntum Exp $

DISTNAME=	avifile-0.53.5
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/			\
		http://divx.euro.ru/					\
		http://www.toon.eu.org/divx/

MAINTAINER=	zuntum@netbsd.org,jmcneill@invisible.yi.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
DEPENDS+=	SDL>=1.1.2:../../devel/SDL
#DEPENDS+=	qt2-libs>=2.1.0:../../x11/qt2-libs
#DEPENDS+=	qt2-designer>=2.1.0:../../x11/qt2-designer
DEPENDS+=	pth>=1.3.7:../../devel/pth
BUILD_DEPENDS+=	unzip-*:../../archivers/unzip

ONLY_FOR_PLATFORM= NetBSD-*-i386
USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}" \
		MOC="${MOC}" \
		UIC="${UIC}" \
#		CPPFLAGS="-I${LOCALBASE}/include"
#		LIBS="-Wl,-R${X11BASE}/qt2/lib -L${X11BASE}/qt2/lib"
CONFIGURE_ARGS+= --prefix=${PREFIX} --with-win32-path=${LOCALBASE}/lib/win32	\
		--enable-sdl --without-qt

#		--enable-timing
#		--with-qt-dir=${X11BASE}/qt2 \
#		--with-qt-includes=${X11BASE}/qt2/include \
#		--with-qt-libraries=${X11BASE}/qt2/lib \

#CONFIGURE_ARGS+= --enable-loader-out # Verbose Win32 DLL loading

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config
MOC?=		${X11BASE}/qt2/bin/moc
UIC?=		${X11BASE}/qt2/bin/uic

.include "../../mk/bsd.pkg.mk"
