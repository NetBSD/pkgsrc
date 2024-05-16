# $NetBSD: Makefile,v 1.44 2024/05/16 06:14:46 wiz Exp $

DISTNAME=	kio-extras-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/internet/
COMMENT=	Additional components to increase the functionality of KIO
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

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

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/kdsoap/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../net/samba4/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kactivities-stats/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
