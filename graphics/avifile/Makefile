# $NetBSD: Makefile,v 1.8 2001/06/24 02:25:51 zuntum Exp $

DISTNAME=	avifile-0.53.5
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/			\
		http://divx.euro.ru/					\
		http://www.toon.eu.org/divx/

MAINTAINER=	zuntum@netbsd.org,jmcneill@invisible.yi.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
DEPENDS+=	SDL>=1.1.2:../../devel/SDL

ONLY_FOR_PLATFORM= NetBSD-*-i386
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}"

CONFIGURE_ARGS+=--prefix=${PREFIX}						\
		--with-win32-path=${LOCALBASE}/lib/win32			\
		--enable-sdl							\
		--without-qt

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config

.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
