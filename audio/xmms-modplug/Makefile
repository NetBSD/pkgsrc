# $NetBSD: Makefile,v 1.14 2006/12/15 14:34:19 wiz Exp $
#

DISTNAME=		modplugxmms-2.05
PKGNAME=		xmms-modplug-2.05
PKGREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		pkgsrc-users@NetBSD.org
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
SUBST_CLASSES+=		mpplay
SUBST_MESSAGE.mpplay=	Skipping modplugplay
SUBST_STAGE.mpplay=	pre-build
SUBST_FILES.mpplay=	Makefile
SUBST_SED.mpplay=       -e 's,^\(SUBDIRS = modplugxmms glade\) modplugplay,\1,'

PLIST_SUBST+=		NOTFOROSX="@comment "
.else
PLIST_SUBST+=		NOTFOROSX=""
.endif

.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
