# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 20:57:39 wiz Exp $
#

DISTNAME=		libvisual-plugins-0.1.7
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Plugins for libvisual

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
# currently not useful, since libgdkpixbuf plugin is not configurable
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
