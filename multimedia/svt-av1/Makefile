# $NetBSD: Makefile,v 1.12 2026/03/27 21:19:27 tnn Exp $

DISTNAME=	svt-av1-3.1.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITLAB:=AOMediaCodec/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/AOMediaCodec/SVT-AV1
COMMENT=	Scalable Video Technology for AV1 (SVT-AV1 Encoder and Decoder)
LICENSE=	modified-bsd

GITLAB_PROJECT=	SVT-AV1
GITLAB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	Source/Lib/pkg-config.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
