# $NetBSD: Makefile,v 1.30 2024/05/29 16:33:08 adam Exp $

DISTNAME=	fcitx5-chinese-addons-5.1.3
PKGREVISION=	3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-chinese-addons/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-chinese-addons
COMMENT=	Pinyin and table input method support for fcitx5
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

DIST_SUBDIR=	${PKGNAME_NOREV}

DISTFILES+=	${DEFAULT_DISTFILES}
MOREDISTFILES+=	py_stroke-20121124.tar.gz
MOREDISTFILES+=	py_table-20121124.tar.gz
.for f in ${MOREDISTFILES}
DISTFILES+=	${f}
SITES.${f}=	https://download.fcitx-im.org/data/
.endfor
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

post-extract:
.for f in ${MOREDISTFILES}
	cd ${WRKSRC}/modules/pinyinhelper && \
		${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${f} ${f}
.endfor

.include "../../devel/cmake/build.mk"
.include "../../converters/opencc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5-lua/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../inputmethod/libime/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
