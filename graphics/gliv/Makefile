# $NetBSD: Makefile,v 1.4 2004/11/30 16:13:53 adam Exp $

DISTNAME=	gliv-1.8.4
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/gliv/
COMMENT=	OpenGL image viewer

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
