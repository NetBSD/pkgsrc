# $NetBSD: kde4.mk,v 1.2 2010/04/10 02:45:03 markd Exp $
#
# This Makefile fragment is included by packages that use the KDE4
# configure-and-build process.
#

.if !defined(KDE4_MK)
KDE4_MK=	# defined

USE_PKGLOCALEDIR=	YES

CMAKE_ARGS+=	-DHTML_INSTALL_DIR=${PREFIX}/share/doc/kde/HTML
CMAKE_ARGS+=	-DDATA_INSTALL_DIR=${PREFIX}/share/kde/apps
CMAKE_ARGS+=	-DCONFIG_INSTALL_DIR=${PREFIX}/share/kde/config
CMAKE_ARGS+=	-DKCFG_INSTALL_DIR=${PREFIX}/share/kde/config.kcfg
CMAKE_ARGS+=	-DLOCALE_INSTALL_DIR=${PREFIX}/${PKGLOCALEDIR}/locale
CMAKE_ARGS+=	-DMIME_INSTALL_DIR=${PREFIX}/share/kde/mimelnk
CMAKE_ARGS+=	-DTEMPLATES_INSTALL_DIR=${PREFIX}/share/kde/templates
CMAKE_ARGS+=	-DWALLPAPER_INSTALL_DIR=${PREFIX}/share/kde/wallpapers
CMAKE_ARGS+=	-DAUTOSTART_INSTALL_DIR=${PREFIX}/share/kde/autostart
CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR=${PKG_SYSCONFDIR:Q}
CMAKE_ARGS+=	-DINFO_INSTALL_DIR=${PREFIX}/${PKGINFODIR}
CMAKE_ARGS+=	-DMAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.4.0
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.4.0
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.endif  # KDE4_MK
