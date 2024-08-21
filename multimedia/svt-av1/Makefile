# $NetBSD: Makefile,v 1.7 2024/08/21 16:59:43 wiz Exp $

DISTNAME=	svt-av1-2.1.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITLAB:=AOMediaCodec/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/AOMediaCodec/SVT-AV1
COMMENT=	Scalable Video Technology for AV1 (SVT-AV1 Encoder and Decoder)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

GITLAB_PROJECT=	SVT-AV1
GITLAB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
