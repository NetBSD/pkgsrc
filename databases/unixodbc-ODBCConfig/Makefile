# $NetBSD: Makefile,v 1.2 2001/12/03 08:09:06 jlam Exp $

PKGNAME=		unixodbc-ODBCConfig-${ODBC_BASE_VERS}
COMMENT=		GUI tool for unixODBC driver configuration

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

MAKE_FLAGS+=		ODBCConfig_DEPENDENCIES=""

_EXTRA_INCLUDES?=	${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
_EXTRA_LIBS?=		${BUILDLINK_DIR}/lib:${BUILDLINK_X11_DIR}/lib
_AC_CV_HAVE_X?=		have_x=yes					\
			kde_x_includes=${BUILDLINK_DIR}/include		\
			ac_x_libraries=${BUILDLINK_DIR}/lib
_AC_CV_HAVE_QT?=	have_qt=yes					\
			ac_qt_includes=${BUILDLINK_QTDIR}/include	\
			ac_qt_libraries=${BUILDLINK_QTDIR}/lib

post-patch: fix-driver-installation

do-build:
	cd ${WRKSRC}/ODBCConfig; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ODBCConfig/ODBCConfig ${PREFIX}/bin

.include "../../databases/unixodbc/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
