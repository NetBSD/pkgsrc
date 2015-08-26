# $NetBSD: Makefile,v 1.49 2015/08/26 11:31:02 leot Exp $

DISTNAME=	xfe-1.40
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roland65.free.fr/xfe/
COMMENT=	Fast MS-Explorer like filemanager for X
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt
GNU_CONFIGURE=		yes

LDFLAGS.DragonFly=	-lXft -lX11
PTHREAD_AUTO_VARS=	yes

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	src/XFileExplorer.cpp
SUBST_SED.conf=		-e "s|/usr/local|${PREFIX}|"
SUBST_MESSAGE.conf=	Fixing hardcoded path.

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/fox/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
