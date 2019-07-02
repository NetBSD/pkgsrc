# $NetBSD: Makefile,v 1.13 2019/07/02 13:13:01 ryoon Exp $

DISTNAME=	keepassxc-${GITHUB_RELEASE}-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	security x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=keepassxreboot/}
GITHUB_RELEASE=	2.4.3
GITHUB_PROJECT=	keepassxc
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keepassxc.org/
COMMENT=	Password generator and manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v3 AND mit AND cc0-1.0-universal

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.if exists(/usr/lib/libjemalloc.so)
LDFLAGS.NetBSD+=	-ljemalloc # for malloc_usable_size()
.endif

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DKEEPASSXC_BUILD_TYPE=Release
CONFIGURE_DIRS=	build

NOT_PAX_MPROTECT_SAFE+=	bin/keepassxc

.PHONY: qmake-bin-add
pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
