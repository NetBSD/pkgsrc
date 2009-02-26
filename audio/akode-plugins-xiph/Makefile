# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 18:12:39 hasso Exp $
#

PKGNAME=		akode-plugins-xiph-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		Xiph decoder plugin for akode framework

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-vorbis
CONFIGURE_ARGS+=	--with-flac
CONFIGURE_ARGS+=	--with-speex

do-install:
	cd ${WRKSRC}/akode/plugins/xiph_decoder && ${SETENV} ${MAKE_ENV} \
		${MAKE} prefix=${DESTDIR}${PREFIX} install

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
