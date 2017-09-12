# $NetBSD: Makefile,v 1.13 2017/09/12 13:51:59 wiz Exp $

DISTNAME=	kio-${KF5VER}
PKGREVISION=	9
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Resource and network access abstraction
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kio/accept-languages.codes \
		${PKG_SYSCONFDIR}/xdg/accept-languages.codes
CONF_FILES+=	${PREFIX}/share/examples/kio/kshorturifilterrc \
		${PKG_SYSCONFDIR}/xdg/kshorturifilterrc

# generation of kcookieserver.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/ioslaves/http/kcookiejar/CMakeFiles/kded_kcookiejar_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/ioslaves/trash/CMakeFiles/kcm_trash_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/urifilters/ikws/CMakeFiles/kurisearchfilter_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/autotests/CMakeFiles/jobremotetest_automoc.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/src/kcms/kio/CMakeFiles/kcm_kio_automoc.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

#.include "../../lang/python/tool.mk"
#.include "../../wip/gpgmepp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kbookmarks/buildlink3.mk"
.include "../../devel/kdoctools/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/kjobwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
