# $NetBSD: Makefile,v 1.1 2026/11/08 16:42:08 ryoon Exp $

DISTNAME=	M88M-1.2.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=bubio/}
GITHUB_PROJECT=	M88M
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/bubio/M88M/
COMMENT=	Modern PC-8801 emulator
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

CWRAPPERS_PREPEND.cxx+=	-L${BUILDLINK_PREFIX.gtk3}/lib
CWRAPPERS_PREPEND.cxx+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

CWRAPPERS_PREPEND.cxx+=	-lglib-2.0 -lgtk-3

.include "../../devel/cmake/build.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../devel/raygui/buildlink3.mk"
.include "../../devel/raylib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/nativefiledialog-extended/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
