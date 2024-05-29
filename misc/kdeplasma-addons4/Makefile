# $NetBSD: Makefile,v 1.114 2024/05/29 16:33:33 adam Exp $

DISTNAME=	kdeplasma-addons-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	52
CATEGORIES=	misc
COMMENT=	Plasmoids

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-D BUILD_ibus:BOOL=OFF
CMAKE_ARGS+=	-DWITH_Marble:BOOL=OFF
CMAKE_ARGS+=	-DWITH_Kexiv2:BOOL=OFF

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../graphics/libkexiv2-kde4/buildlink3.mk"
BUILDLINK_API_DEPENDS.eigen2+=	eigen2>=2.0.3
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
#.include "../../math/qalculate/buildlink3.mk"
.include "../../misc/attica/buildlink3.mk"
#.include "../../misc/marble/buildlink3.mk"
#.include "../../misc/nepomuk-core/buildlink3.mk"
#.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../security/qoauth/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
