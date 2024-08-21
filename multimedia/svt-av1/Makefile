# $NetBSD: Makefile,v 1.8 2024/08/21 17:21:44 wiz Exp $

DISTNAME=	svt-av1-2.2.0
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

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

PKGCONFIG_OVERRIDE+=	Source/Lib/pkg-config.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
