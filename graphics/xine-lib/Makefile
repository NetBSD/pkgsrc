# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 11:06:02 rh Exp $
#

DISTNAME=		xine-lib-1-beta9
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

CONFIGURE_ARGS+=	--with-w32-path='${PREFIX}/lib/win32'

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../graphics/xvidcore/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
