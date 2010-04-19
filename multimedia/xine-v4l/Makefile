# $NetBSD: Makefile,v 1.1 2010/04/19 15:33:25 drochner Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/v4l2/}
CATEGORIES=	multimedia
COMMENT=	The v4l input plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/input
CONFIGURE_ARGS+=	--without-x

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/input && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_inp_v4l.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
