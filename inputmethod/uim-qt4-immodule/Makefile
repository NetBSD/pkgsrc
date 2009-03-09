# $NetBSD: Makefile,v 1.2 2009/03/09 12:45:53 hasso Exp $

.include		"../../inputmethod/uim/Makefile.common"
PKGNAME=		uim-qt4-immodule-${UIM_VERSION}
CATEGORIES=		inputmethod

COMMENT=		Qt4 immodule for inputmethod/uim

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=          YES
CONFIGURE_ARGS+=	--with-libgcroots=installed
CONFIGURE_ARGS+=	--with-qt4-immodule
CONFIGURE_ARGS+=	--with-libedit=no
CONFIGURE_ARGS+=	--disable-emacs
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

INSTALL_DIRS=	qt4/immodule

do-build:
	${RUN} cd ${WRKSRC}/uim && ${BUILD_MAKE_CMD} libuim-x-util.la
	${RUN} cd ${WRKSRC}/replace && ${BUILD_MAKE_CMD} ${BUILD_TARGET}
	${RUN} cd ${WRKSRC}/qt4/immodule && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

.include "../../inputmethod/uim/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
