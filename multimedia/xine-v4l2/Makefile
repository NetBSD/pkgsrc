# $NetBSD: Makefile,v 1.16 2016/08/17 00:06:45 ryoon Exp $

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/v4l2/}
PKGREVISION=	4
CATEGORIES=	multimedia
COMMENT=	The v4l2 input plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	src/input
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/input && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_inp_v4l2.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}; \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_inp_pvr.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
