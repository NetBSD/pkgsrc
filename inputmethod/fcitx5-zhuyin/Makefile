# $NetBSD: Makefile,v 1.3 2021/03/02 13:24:54 ryoon Exp $

DISTNAME=	fcitx5-zhuyin-5.0.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-zhuyin/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-zhuyin
COMMENT=	Libzhuyin Wrapper for Fcitx5
LICENSE=	gnu-gpl-v2

DISTFILES+=	${DEFAULT_DISTFILES}
MOREDISTFILES+=	model.text.20161206.tar.gz
.for f in ${MOREDISTFILES}
DISTFILES+=	${f}
SITES.${f}=	https://download.fcitx-im.org/data/
.endfor
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

post-extract:
.for f in ${MOREDISTFILES}
	cd ${WRKSRC}/data && \
		${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${f} ${f}
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/libpinyin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
