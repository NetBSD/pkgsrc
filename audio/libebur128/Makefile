# $NetBSD: Makefile,v 1.10 2025/08/16 08:15:15 adam Exp $

DISTNAME=	libebur128-1.2.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiixyj/}
GITHUB_PROJECT=	libebur128
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/libebur128
COMMENT=	EBU R128 loudness standard implementation
LICENSE=	mit

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	ebur128/libebur128.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
