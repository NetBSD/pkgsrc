# $NetBSD: Makefile,v 1.62 2026/01/27 08:39:13 wiz Exp $

DISTNAME=	kio-extras-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/internet/
COMMENT=	Additional components to increase the functionality of KIO
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config perl:run

REPLACE_PERL+=	info/kde-info2html

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	info/kde-info2html.conf
SUBST_VARS.paths=	LOCALBASE
SUBST_STAGE.paths=	pre-configure

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
TOOL_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum
.endif

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kpty/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/qcoro/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../multimedia/phonon-qt6/buildlink3.mk"
.include "../../net/kf6-kdnssd/buildlink3.mk"
.include "../../net/kdsoap/buildlink3.mk"
.include "../../net/kdsoap-ws-discovery-client/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../net/samba4/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities-stats/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
