# $NetBSD: Makefile,v 1.26 2019/07/24 18:11:04 nia Exp $

DISTNAME=	faad2-2.8.8
PKGNAME=	${DISTNAME:S/faad/xmms-faad/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.audiocoding.com/
COMMENT=	XMMS plugin for faad
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xmms
CONFIGURE_ARGS+=	--with-mp4v2

SHLIBTOOL_OVERRIDE=	# empty
DISTINFO_FILE=		${.CURDIR}/../../audio/faad2/distinfo
PATCHDIR=		${.CURDIR}/../../audio/faad2/patches

BUILD_DIRS=		plugins/xmms/src
INSTALL_DIRS=		plugins/xmms

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
