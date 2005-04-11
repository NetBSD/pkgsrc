# $NetBSD: Makefile,v 1.6 2005/04/11 21:46:03 tv Exp $

DISTNAME=	gliv-1.9.1
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/gliv/
COMMENT=	OpenGL image viewer

BUILD_USES_MSGFMT=	yes

USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
