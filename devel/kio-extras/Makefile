# $NetBSD: Makefile,v 1.1 2021/02/11 20:34:28 markd Exp $

DISTNAME=	kio-extras-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/internet/
COMMENT=	Additional components to increase the functionality of KIO
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config perl:run

REPLACE_PERL+=	info/kde-info2html

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	info/kde-info2html.conf
SUBST_VARS.paths=	LOCALBASE
SUBST_STAGE.paths=	pre-configure

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/kdsoap/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kactivities-stats/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
