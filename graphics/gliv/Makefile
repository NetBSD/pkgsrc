# $NetBSD: Makefile,v 1.8 2005/06/01 18:02:56 jlam Exp $

DISTNAME=	gliv-1.9.1
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/gliv/
COMMENT=	OpenGL image viewer

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
