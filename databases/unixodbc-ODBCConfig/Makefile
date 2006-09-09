# $NetBSD: Makefile,v 1.20 2006/09/09 02:41:56 obache Exp $

PKGNAME=		unixodbc-ODBCConfig-${ODBC_BASE_VERS}
PKGREVISION=		3
COMMENT=		GUI tool for unixODBC driver configuration

.include "../../databases/unixodbc/Makefile.common"

CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-extra-includes=${_EXTRA_INCLUDES:Q}
CONFIGURE_ARGS+=	--with-extra-libs=${_EXTRA_LIBS:Q}
CONFIGURE_ARGS+=	--disable-rpath

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		USER_LDFLAGS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		ac_cv_have_x=${_AC_CV_HAVE_X:Q}
CONFIGURE_ENV+=		ac_cv_have_qt=${_AC_CV_HAVE_QT:Q}

USE_LANGUAGES=		c c++

_EXTRA_INCLUDES?=	${LOCALBASE}/include:${X11BASE}/include
_EXTRA_LIBS?=		${LOCALBASE}/lib:${X11BASE}/lib
_AC_CV_HAVE_X?=		have_x=yes					\
			kde_x_includes=${LOCALBASE}/include		\
			ac_x_libraries=${LOCALBASE}/lib
_AC_CV_HAVE_QT?=	have_qt=yes					\
			ac_qt_includes=${QTDIR}/include			\
			ac_qt_libraries=${QTDIR}/lib

INSTALLATION_DIRS=	bin

post-patch: fix-driver-installation

do-build:
	cd ${WRKSRC}/ODBCConfig; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ODBCConfig/ODBCConfig ${PREFIX}/bin

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
