# $NetBSD: Makefile,v 1.3 2009/06/08 18:54:21 hasso Exp $
#

PKGNAME=		akode-plugins-sun-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		Sun audio output plugin for akode framework
LICENSE=		gnu-lgpl-v2

ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-sun

do-install:
	cd ${WRKSRC}/akode/plugins/sun_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		prefix=${DESTDIR}${PREFIX} install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
