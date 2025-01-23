# $NetBSD: Makefile,v 1.20 2025/01/23 23:27:28 riastradh Exp $

DISTNAME=	libime-1.1.5
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/libime/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/libime
COMMENT=	Generic inputmethod implementation library
LICENSE=	gnu-lgpl-v2.1

DICTDISTFILES+=	lm_sc.arpa-20230712.tar.xz
DICTDISTFILES+=	dict-20230412.tar.xz
DICTDISTFILES+=	table-20240108.tar.gz

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}
.for f in ${DICTDISTFILES}
DISTFILES+=	${f}
SITES.${f}=	https://download.fcitx-im.org/data/
.endfor

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE+=	27

post-extract:
.for f in ${DICTDISTFILES}
	cd ${WRKSRC}/data && \
		${LN} -sf ${DISTDIR}/${f} ${f}
.endfor

.include "../../devel/cmake/build.mk"

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
