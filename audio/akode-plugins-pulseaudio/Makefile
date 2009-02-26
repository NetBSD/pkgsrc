# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 18:09:05 hasso Exp $
#

PKGNAME=		akode-plugins-pulseaudio-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		Pulseaudio output plugin for akode framework

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-polypaudio

do-install:
	cd ${WRKSRC}/akode/plugins/polyp_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		prefix=${DESTDIR}${PREFIX} install

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
