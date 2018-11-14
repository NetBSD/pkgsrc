# $NetBSD: Makefile,v 1.86 2018/11/14 22:21:29 kleink Exp $

DISTNAME=	gcompris-12.11
PKGREVISION=	36
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcompris/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://gcompris.net/
COMMENT=	Educational games for children
LICENSE=	gnu-gpl-v3

DEPENDS+=	gnuchess-[0-9]*:../../games/gnuchess

USE_TOOLS+=		gmake intltool gtar pkg-config msgfmt texi2html
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CHECK_PORTABILITY_SKIP+= macosx/build-gtk.sh
INFO_FILES=		yes

PTHREAD_AUTO_VARS=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-sqlite2, py-gtk2

PKG_SUPPORTED_OPTIONS=	gnet
PKG_OPTIONS_VAR=	PKG_OPTIONS.gcompris
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mgnet)
CONFIGURE_ARGS+=	--disable-gnet
.else
.include "../../net/gnet/buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--enable-sdlmixer

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

post-install:
	rm ${DESTDIR}${PREFIX}/share/gcompris/boards/anim/Makefile
	rm ${DESTDIR}${PREFIX}/share/gcompris/boards/anim/Makefile.am
	rm ${DESTDIR}${PREFIX}/share/gcompris/boards/anim/Makefile.in
	rm ${DESTDIR}${PREFIX}/share/gcompris/boards/geo_country/usa/Makefile.am
	rm ${DESTDIR}${PREFIX}/share/gcompris/boards/gnumch/Makefile.am

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
