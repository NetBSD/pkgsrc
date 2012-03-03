# $NetBSD: Makefile,v 1.10 2012/03/03 00:12:36 wiz Exp $
#

PKGNAME=		akode-plugins-pulseaudio-${AKODE_VERSION}
PKGREVISION=		6

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Pulseaudio output plugin for akode framework
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-polypaudio

do-install:
	cd ${WRKSRC}/akode/plugins/polyp_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		DESTDIR=${DESTDIR} install

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
