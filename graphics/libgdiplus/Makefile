# $NetBSD: Makefile,v 1.7 2004/05/11 17:37:48 recht Exp $
#

DISTNAME=	libgdiplus-0.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.go-mono.com/archive/beta1/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.go-mono.com/archive/
COMMENT=	Implementation of the GDI+ API

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libgdiplus.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
