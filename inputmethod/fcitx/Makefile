# $NetBSD: Makefile,v 1.31 2022/08/11 05:08:50 gutteridge Exp $
#

DISTNAME=		fcitx-4.2.9.6
PKGREVISION=		15
CATEGORIES=		inputmethod
MASTER_SITES=		https://download.fcitx-im.org/fcitx/
EXTRACT_SUFX=		.tar.xz

DISTFILES=		${DEFAULT_DISTFILES}

DATAFILES=		en_dict-20121020.tar.gz
DATAFILES+=		pinyin.tar.gz
DATAFILES+=		py_stroke-20121124.tar.gz
DATAFILES+=		py_table-20121124.tar.gz
DATAFILES+=		table.tar.gz

EXTRACT_ONLY=		${DEFAULT_DISTFILES}

.for f in ${DATAFILES}
SITES.${f}=		https://download.fcitx-im.org/data/
DISTFILES+=		${f}
.endfor

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		https://www.fcitx-im.org/
COMMENT=		Free Chinese Input Toy of X

BUILD_DEPENDS+=		extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_LANGUAGES+=		c c++

USE_TOOLS+=		bash:run gmake pkg-config
USE_CMAKE=		yes

REPLACE_BASH+=		data/script/*sh
REPLACE_BASH+=		cmake/*sh

CMAKE_ARGS+=		-DENABLE_PRESAGE=OFF
CMAKE_ARGS+=		-DENABLE_GIR=OFF
CMAKE_ARGS+=		-DENABLE_GTK2_IM_MODULE=ON
CMAKE_ARGS+=		-DENABLE_GTK3_IM_MODULE=ON
CMAKE_ARGS+=		-DENABLE_QT=OFF
CMAKE_ARGS+=		-DENABLE_QT_IM_MODULE=OFF
CMAKE_ARGS+=		-DENABLE_QT_GUI=OFF

BUILDLINK_DEPMETHOD.libXt?=	build

PTHREAD_AUTO_VARS=	yes
LDFLAGS.NetBSD+=	-lexecinfo -lintl
BUILDLINK_TRANSFORM+=	rm:-Wl,--as-needed

post-extract:
	${CP} ${DISTDIR}/en_dict-20121020.tar.gz \
		${WRKSRC}/src/module/spell/dict/
	${CP} ${DISTDIR}/pinyin.tar.gz \
		${WRKSRC}/src/im/pinyin/data/
	${CP} ${DISTDIR}/py_stroke-20121124.tar.gz \
		${WRKSRC}/src/module/pinyin-enhance/data/
	${CP} ${DISTDIR}/py_table-20121124.tar.gz \
		${WRKSRC}/src/module/pinyin-enhance/data/
	${CP} ${DISTDIR}/table.tar.gz \
		${WRKSRC}/src/im/table/data/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
