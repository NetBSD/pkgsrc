# $NetBSD: Makefile,v 1.1.1.1 2001/11/06 04:10:12 jlam Exp $

PKGNAME=		unixodbc-DataManager-${ODBC_VERS}
ODBC_PKG_VERS=		# empty
COMMENT=		GUI tool for unixODBC data source management

USE_BUILDLINK_ONLY=	YES

.include "../../databases/unixodbc/Makefile.common"

CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--with-qt-dir="${BUILDLINK_QTDIR}"
CONFIGURE_ARGS+=	--with-extra-includes="${_EXTRA_INCLUDES}"
CONFIGURE_ARGS+=	--with-extra-libs="${_EXTRA_LIBS}"
CONFIGURE_ARGS+=	--disable-rpath

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV+=		ac_cv_have_x="${_AC_CV_HAVE_X}"
CONFIGURE_ENV+=		ac_cv_have_qt="${_AC_CV_HAVE_QT}"

MAKE_FLAGS+=		DataManager_DEPENDENCIES=""

_EXTRA_INCLUDES?=	${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
_EXTRA_LIBS?=		${BUILDLINK_DIR}/lib:${BUILDLINK_X11_DIR}/lib
_AC_CV_HAVE_X?=		have_x=yes					\
			kde_x_includes=${BUILDLINK_DIR}/include		\
			ac_x_libraries=${BUILDLINK_DIR}/lib
_AC_CV_HAVE_QT?=	have_qt=yes					\
			ac_qt_includes=${BUILDLINK_QTDIR}/include	\
			ac_qt_libraries=${BUILDLINK_QTDIR}/lib

do-build:
	cd ${WRKSRC}/DataManager; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DataManager/DataManager ${PREFIX}/bin

.include "../../databases/unixodbc/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
