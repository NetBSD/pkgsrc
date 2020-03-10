# $NetBSD: Makefile,v 1.83 2020/03/10 22:10:05 wiz Exp $

DISTNAME=	geeqie-1.5.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.geeqie.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.geeqie.org/
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lm -lsocket -lnsl

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		bash:run gmake intltool msgfmt pkg-config automake autoconf autoreconf

REPLACE_BASH+=		plugins/*/*
REPLACE_BASH+=		gen_changelog.sh

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-build:
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM} html

.include "options.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
