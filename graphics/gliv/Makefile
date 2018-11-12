# $NetBSD: Makefile,v 1.56 2018/11/12 03:52:12 ryoon Exp $

DISTNAME=	gliv-1.9.6
PKGREVISION=	30
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/gliv/
COMMENT=	OpenGL image viewer

USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gawk gmake msgfmt pkg-config
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/pixmaps share/applications

post-install:
	${INSTALL_DATA} ${WRKSRC}/gliv.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gliv.desktop \
		${DESTDIR}${PREFIX}/share/applications/gnome-gliv.desktop

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
