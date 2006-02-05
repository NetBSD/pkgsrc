# $NetBSD: Makefile,v 1.11 2006/02/05 23:08:18 joerg Exp $
#

DISTNAME=		modplugxmms-2.05
PKGNAME=		xmms-modplug-2.05
PKGREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		XMMS plugin based on modplug

DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

LDFLAGS+=		-lm ${LIBOSSAUDIO}
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool-disable-static
USE_TOOLS+=		pkg-config

CFLAGS+=		-DDEVICE_NAME="\"${DEVOSSSOUND}\""
USE_LANGUAGES=		c c++

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
