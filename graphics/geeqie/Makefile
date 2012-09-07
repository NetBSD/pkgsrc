# $NetBSD: Makefile,v 1.24 2012/09/07 19:16:44 adam Exp $
#

DISTNAME=	geeqie-1.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geeqie/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://geeqie.sourceforge.net/
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gps

LDFLAGS.SunOS+=		-lm -lsocket -lnsl

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		bash:run gmake intltool msgfmt pkg-config

REPLACE_BASH=		plugins/rotate/geeqie-rotate
REPLACE_BASH+=		plugins/ufraw/geeqie-ufraw
REPLACE_BASH+=		plugins/import/geeqie-import

post-build:
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM} html

.include "../../geography/libchamplain04/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
