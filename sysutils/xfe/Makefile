# $NetBSD: Makefile,v 1.56 2023/01/12 10:20:34 wiz Exp $

DISTNAME=	xfe-1.45
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roland65.free.fr/xfe/
COMMENT=	Fast MS-Explorer like filemanager for X
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake
USE_TOOLS+=		intltool msgfmt msgmerge xgettext
GNU_CONFIGURE=		yes

LDFLAGS.DragonFly=	-lXft -lX11
PTHREAD_AUTO_VARS=	yes

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	src/XFileExplorer.cpp src/xfedefs.h
SUBST_SED.conf=		-e "s|/usr/local|${PREFIX}|"
SUBST_MESSAGE.conf=	Fixing hardcoded path.

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/fox/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
