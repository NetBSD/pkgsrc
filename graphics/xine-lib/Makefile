# $NetBSD: Makefile,v 1.16 2003/12/08 14:41:40 wiz Exp $
#

DISTNAME=		xine-lib-1-rc0a
PKGNAME=		xine-lib-1rc0a
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		Multimedia player library

BUILD_USES_MSGFMT=	YES
.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       win32-codecs>=011227:../../graphics/win32-codecs
PLIST_SRC=		${PKGDIR}/PLIST.i386
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool-nofpic
PKGCONFIG_OVERRIDE=	${WRKSRC}/misc/libxine.pc.in
USE_GMAKE=		yes

CONFIGURE_ARGS+=	--with-w32-path='${PREFIX}/lib/win32'
CONFIGURE_ENV+=		have_libpng="yes"
CONFIGURE_ENV+=		PNG_CFLAGS="-I${PREFIX}/include"
CONFIGURE_ENV+=		PNG_LIBS="-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpng"

.if !exists(${X11BASE}/lib/libXv.so)
PLIST_SUBST+=		XV_WORKAROUND="@comment "
.else
PLIST_SUBST+=		XV_WORKAROUND=""
.endif

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xvidcore/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
