# $NetBSD: Makefile,v 1.57 2016/05/29 20:40:16 wiz Exp $

DISTNAME=	geeqie-1.3
EXTRACT_SUFX=	.tar.xz
CATEGORIES=	graphics
MASTER_SITES=	http://www.geeqie.org/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.geeqie.org/
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lm -lsocket -lnsl

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		bash:run gmake intltool msgfmt pkg-config automake autoconf autoreconf

REPLACE_BASH=		plugins/rotate/geeqie-rotate
REPLACE_BASH+=		plugins/ufraw/geeqie-ufraw
REPLACE_BASH+=		plugins/import/geeqie-import

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

post-build:
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM} html

.include "options.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
