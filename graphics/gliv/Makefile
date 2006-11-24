# $NetBSD: Makefile,v 1.22 2006/11/24 15:44:25 drochner Exp $

DISTNAME=	gliv-1.9.6
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/gliv/
COMMENT=	OpenGL image viewer

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/gliv.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gliv.desktop \
		${PREFIX}/share/applications/gnome-gliv.desktop

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
