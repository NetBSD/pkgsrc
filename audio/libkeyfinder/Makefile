# $NetBSD: Makefile,v 1.3 2025/08/20 11:34:46 wiz Exp $

DISTNAME=	libkeyfinder-2.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mixxxdj/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mixxxdj.github.io/libkeyfinder/
COMMENT=	Musical key detection for digital audio
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	libkeyfinder.pc.in

.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
