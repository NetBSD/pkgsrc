# $NetBSD: Makefile,v 1.5 2011/11/16 01:33:16 sbd Exp $
#

PKGNAME=		akode-plugins-ffmpeg-${AKODE_VERSION}
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		FFMPEG decoder plugin for akode framework
LICENSE=		gnu-lgpl-v2

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
