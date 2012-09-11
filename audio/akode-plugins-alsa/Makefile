# $NetBSD: Makefile,v 1.6 2012/09/11 23:59:21 asau Exp $
#

PKGNAME=		akode-plugins-alsa-${AKODE_VERSION}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Alsa output plugin for aKode framework
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-alsa

do-install:
	cd ${WRKSRC}/akode/plugins/alsa_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		DESTDIR=${DESTDIR} install

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
