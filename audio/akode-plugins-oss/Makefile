# $NetBSD: Makefile,v 1.7 2015/11/07 20:46:20 dholland Exp $
#

PKGNAME=		akode-plugins-oss-${AKODE_VERSION}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OSS output plugin for akode framework
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-oss

# MacOS doesn't have OSS
NOT_FOR_PLATFORM=	Darwin-*-*

do-install:
	cd ${WRKSRC}/akode/plugins/oss_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		DESTDIR=${DESTDIR} install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
