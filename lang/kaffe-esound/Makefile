# $NetBSD: Makefile,v 1.10 2012/01/13 10:55:16 obache Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=		${DISTNAME:S/kaffe/kaffe-esound/}
PKGREVISION=		2

COMMENT+=		(sound support through esound)

CONFIGURE_ARGS+=	--disable-native-awt
CONFIGURE_ARGS+=	--disable-gtk-peer
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-esd

BUILD_DIRS=		config
BUILD_DIRS+=		libraries/javalib
BUILD_DIRS+=		libraries/clib/sound/esd
INSTALL_DIRS=		libraries/clib/sound/esd

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} BUILD_ENVIRONMENT

.include "../../audio/esound/buildlink3.mk"
.include "../../lang/kaffe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
