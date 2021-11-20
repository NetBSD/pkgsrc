# $NetBSD: Makefile,v 1.1 2021/11/20 18:09:45 nia Exp $

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

CMAKE_ARGS+=	-DBUILD_TESTING=OFF

PKGCONFIG_OVERRIDE+=	libkeyfinder.pc.in

.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
