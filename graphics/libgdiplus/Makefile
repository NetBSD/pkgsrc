# $NetBSD: Makefile,v 1.9 2004/07/03 23:03:21 recht Exp $
#

DISTNAME=	libgdiplus-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://mono2.ximian.com/archive/1.0/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Implementation of the GDI+ API

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libgdiplus.pc.in
GNU_CONFIGURE=		yes

# XXX gdip_win32.c uses pthread, but
# configure doesn't check for it...
#CFLAGS+=	${PTHREAD_CFLAGS}
#LDFLAGS+=	${PTHREAD_LDFLAGS}

pre-configure:
	cd ${WRKSRC};			\
	${AUTOHEADER};			\
	${AUTOCONF}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
