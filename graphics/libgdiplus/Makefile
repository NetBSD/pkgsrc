# $NetBSD: Makefile,v 1.3 2004/02/14 18:26:28 jmmv Exp $
#

DISTNAME=	libgdiplus-0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.go-mono.com/archive/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.go-mono.com/archive/
COMMENT=	Implementation of the GDI+ API

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libgdiplus.pc.in
GNU_CONFIGURE=		yes

.include "../../graphics/cairo/buildlink2.mk"
.include "../../lang/mono/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
