# $NetBSD: Makefile,v 1.36 2024/01/22 13:17:05 ryoon Exp $

PKGREVISION= 6
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/v4l/}
CATEGORIES=	multimedia
COMMENT=	The v4l input plugin for xine-lib

# NetBSD supports only v4l2, whose plugin is in ../xine-v4l2.
NOT_FOR_PLATFORM=	NetBSD-*-*

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=		src/input
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/input && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_inp_v4l.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
