# $NetBSD: Makefile,v 1.9 2015/11/07 20:47:03 dholland Exp $
#

PKGNAME=		akode-plugins-sun-${AKODE_VERSION}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sun audio output plugin for akode framework
LICENSE=		gnu-lgpl-v2

# no support for the sun audio interface
NOT_FOR_PLATFORM+=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*

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
