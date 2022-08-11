# $NetBSD: Makefile,v 1.96 2022/08/11 05:08:41 gutteridge Exp $

DISTNAME=	geeqie-1.7.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=BestImageViewer/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.geeqie.org/
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lm -lsocket -lnsl

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		bash:run gmake intltool msgfmt pkg-config automake autoconf autoreconf

REPLACE_BASH+=		plugins/*/*
REPLACE_BASH+=		doc/*.sh
REPLACE_BASH+=		g*.sh
REPLACE_BASH+=		version.sh

pre-configure: replace-interpreter
	cd ${WRKSRC} && autoreconf -fiv

.include "options.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gnome-doc-utils+=	gnome-doc-utils>=0.20.10nb4
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
