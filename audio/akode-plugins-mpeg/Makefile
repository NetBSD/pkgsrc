# $NetBSD: Makefile,v 1.2 2009/06/08 18:54:21 hasso Exp $
#

PKGNAME=		akode-plugins-mpeg-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		MPEG plugin for akode framework
LICENSE=		gnu-gpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-libmad

do-install:
	cd ${WRKSRC}/akode/plugins/mpeg_decoder && ${SETENV} ${MAKE_ENV} \
		${MAKE} prefix=${DESTDIR}${PREFIX} install

.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
