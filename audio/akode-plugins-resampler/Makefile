# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 18:10:34 hasso Exp $
#

PKGNAME=		akode-plugins-resampler-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		Resampler plugin for aKode framework

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-libsamplerate

do-install:
	cd ${WRKSRC}/akode/plugins/src_resampler && ${SETENV} ${MAKE_ENV} \
		${MAKE} prefix=${DESTDIR}${PREFIX} install

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
