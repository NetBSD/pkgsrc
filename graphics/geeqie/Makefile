# $NetBSD: Makefile,v 1.87 2020/06/02 08:24:01 adam Exp $

DISTNAME=	geeqie-1.5.1
PKGREVISION=	5
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

.include "options.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gnome-doc-utils+=	gnome-doc-utils>=0.20.10nb4
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
