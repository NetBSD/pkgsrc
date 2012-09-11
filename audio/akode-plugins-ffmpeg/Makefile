# $NetBSD: Makefile,v 1.8 2012/09/11 23:59:22 asau Exp $
#

PKGNAME=		akode-plugins-ffmpeg-${AKODE_VERSION}
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		FFMPEG decoder plugin for akode framework
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-ffmpeg

do-install:
	cd ${WRKSRC}/akode/plugins/ffmpeg_decoder && ${SETENV} ${MAKE_ENV} \
		${MAKE} DESTDIR=${DESTDIR} install

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
