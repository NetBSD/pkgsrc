# $NetBSD: Makefile,v 1.6 2021/02/10 10:15:00 nia Exp $

DISTNAME=	libebur128-1.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiixyj/}
GITHUB_PROJECT=	libebur128
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/libebur128
COMMENT=	EBU R128 loudness standard implementation
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	ebur128/libebur128.pc.cmake

.include "../../audio/speex/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
