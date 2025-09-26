# $NetBSD: Makefile,v 1.1 2025/09/26 18:30:41 js Exp $

DISTNAME=	mt32emu-2.7.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=munt/}
GITHUB_PROJECT=	munt
GITHUB_TAG=	libmt32emu_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munt.sourceforge.net/
COMMENT=	C/C++ library for emulating Roland MT-32, CM-32L and LAPC-I
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-Dmunt_WITH_MT32EMU_SMF2WAV=FALSE
CMAKE_CONFIGURE_ARGS+=	-Dmunt_WITH_MT32EMU_QT=FALSE

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
