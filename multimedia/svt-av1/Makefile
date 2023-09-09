# $NetBSD: Makefile,v 1.4 2023/09/09 20:19:00 wiz Exp $

DISTNAME=	svt-av1-1.7.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITLAB:=AOMediaCodec/}
EXTRACT_SUFX=	.tar.bz2

GITLAB_PROJECT=	SVT-AV1
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/AOMediaCodec/SVT-AV1
COMMENT=	Scalable Video Technology for AV1 (SVT-AV1 Encoder and Decoder)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-G"Unix Makefiles"
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

CONFIGURE_DIRS=	Build

.include "../../mk/bsd.pkg.mk"
