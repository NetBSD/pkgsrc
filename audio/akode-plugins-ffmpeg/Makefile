# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 18:04:42 hasso Exp $
#

PKGNAME=		akode-plugins-ffmpeg-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		FFMPEG decoder plugin for akode framework

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-ffmpeg

do-install:
	cd ${WRKSRC}/akode/plugins/ffmpeg_decoder && ${SETENV} ${MAKE_ENV} \
		${MAKE} prefix=${DESTDIR}${PREFIX} install

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
