# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 18:06:08 hasso Exp $
#

PKGNAME=		akode-plugins-mpc-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		MPC decoder plugin for akode framework

.include "../../audio/akode/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../audio/akode/distinfo
PATCHDIR=		${.CURDIR}/../../audio/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-mpc

do-install:
	cd ${WRKSRC}/akode/plugins/mpc_decoder && ${SETENV} ${MAKE_ENV} \
		${MAKE} prefix=${DESTDIR}${PREFIX} install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
