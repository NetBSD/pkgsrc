# $NetBSD: Makefile,v 1.15 2023/12/25 18:01:48 wiz Exp $

DISTNAME=	libime-1.0.4
PKGREVISION=	8
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/libime/
EXTRACT_SUFX=	.tar.xz
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/libime
COMMENT=	Generic inputmethod implementation library
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

DICTDISTFILES+=	lm_sc.3gm.arpa-20140820.tar.bz2
#ICTDISTFILES+=	dict.utf8-20200715.tar.xz
DICTDISTFILES+=	dict.utf8-20210203.tar.xz
DICTDISTFILES+=	table.tar.gz

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}
.for f in ${DICTDISTFILES}
DISTFILES+=	${f}
SITES.${f}=	https://download.fcitx-im.org/data/
.endfor

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE+=	27
# possibly fixed in 1.0.17?
PYTHON_VERSIONS_INCOMPATIBLE+=	311 312

post-extract:
.for f in ${DICTDISTFILES}
	cd ${WRKSRC}/data && \
		${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${f} ${f}
.endfor

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
