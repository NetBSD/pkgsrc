# $NetBSD: Makefile,v 1.7 2013/02/09 22:11:31 ryoon Exp $
#

PKGNAME=		akode-plugins-jack-${AKODE_VERSION}
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Jack output plugin for aKode framework
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

CONFIGURE_ARGS+=	--with-jack

do-install:
	cd ${WRKSRC}/akode/plugins/jack_sink && ${SETENV} ${MAKE_ENV} ${MAKE} \
		DESTDIR=${DESTDIR} install

.include "../../audio/jack/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
