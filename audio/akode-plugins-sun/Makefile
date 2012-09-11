# $NetBSD: Makefile,v 1.7 2012/09/11 23:59:22 asau Exp $
#

PKGNAME=		akode-plugins-sun-${AKODE_VERSION}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sun audio output plugin for akode framework
LICENSE=		gnu-lgpl-v2

ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-sun

do-install:
	cd ${WRKSRC}/akode/plugins/sun_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		DESTDIR=${DESTDIR} install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
