# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:55 tv Exp $
#

DISTNAME=	libgdiplus-1.0.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.go-mono.com/archive/1.0.1/

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
