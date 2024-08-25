# $NetBSD: Makefile,v 1.2 2024/08/25 06:18:24 wiz Exp $

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

PKGCONFIG_OVERRIDE+=	libkeyfinder.pc.in

.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
