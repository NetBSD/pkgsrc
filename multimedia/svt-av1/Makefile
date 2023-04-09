# $NetBSD: Makefile,v 1.1 2023/04/09 11:13:51 plunky Exp $

DISTNAME=	svt-av1-1.4.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITLAB:=AOMediaCodec/}
EXTRACT_SUFX=	.tar.bz2

GITLAB_PROJECT=	SVT-AV1
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/AOMediaCodec/SVT-AV1
COMMENT=	Scalable Video Technology for AV1 (SVT-AV1 Encoder and Decoder)
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-G"Unix Makefiles"
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

CONFIGURE_DIRS=	Build

.include "../../mk/bsd.pkg.mk"
