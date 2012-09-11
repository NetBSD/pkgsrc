# $NetBSD: Makefile,v 1.6 2012/09/11 23:59:22 asau Exp $
#

PKGNAME=		akode-plugins-resampler-${AKODE_VERSION}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Resampler plugin for aKode framework
LICENSE=		gnu-gpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-libsamplerate

do-install:
	cd ${WRKSRC}/akode/plugins/src_resampler && ${SETENV} ${MAKE_ENV} \
		${MAKE} DESTDIR=${DESTDIR} install

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
