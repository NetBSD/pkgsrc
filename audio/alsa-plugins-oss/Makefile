# $NetBSD: Makefile,v 1.3 2009/07/07 14:45:41 joerg Exp $
#

DISTNAME=	alsa-plugins-1.0.18
PKGNAME=	${DISTNAME:S/plugins/plugins-oss/}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) - OSS plugin

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
LIBS+=		${LIBOSSAUDIO}

BUILD_DIRS=	oss

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
