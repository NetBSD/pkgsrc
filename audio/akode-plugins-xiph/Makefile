# $NetBSD: Makefile,v 1.6 2012/09/11 23:59:23 asau Exp $
#

PKGNAME=		akode-plugins-xiph-${AKODE_VERSION}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Xiph decoder plugin for akode framework
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-vorbis
CONFIGURE_ARGS+=	--with-flac
CONFIGURE_ARGS+=	--with-speex

do-install:
	cd ${WRKSRC}/akode/plugins/xiph_decoder && ${SETENV} ${MAKE_ENV} \
		${MAKE} DESTDIR=${DESTDIR} install

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
