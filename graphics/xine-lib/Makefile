# $NetBSD: Makefile,v 1.5 2003/05/05 16:32:29 jmmv Exp $
#

DISTNAME=		xine-lib-1-beta10
PKGREVISION=		1
PKGNAME=		${DISTNAME:S/-beta/.0rc/}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		multimedia player library

BUILD_USES_MSGFMT=	YES
.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       win32-codecs>=011227:../../graphics/win32-codecs
.endif

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool-nofpic
PKGCONFIG_OVERRIDE=	${WRKSRC}/misc/libxine.pc.in

CONFIGURE_ARGS+=	--with-w32-path='${PREFIX}/lib/win32'
CONFIGURE_ENV+=		have_libpng="yes"
CONFIGURE_ENV+=		PNG_CFLAGS="-I${PREFIX}/include"
CONFIGURE_ENV+=		PNG_LIBS="-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpng"

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
