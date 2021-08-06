# $NetBSD: Makefile,v 1.1 2021/08/06 13:50:24 nia Exp $

V=		0.3.4
PKGNAME=	libaudec-${V}
CATEGORIES=	audio
DISTFILES+=	libaudec-${V}.tar.gz

SITES.libaudec-${V}.tar.gz=	\
	-https://git.sr.ht/~alextee/libaudec/archive/v${V}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alextee/libaudec
COMMENT=	Audio decoding library
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/libaudec-v${V}

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/audec.pc

.include "../../devel/meson/build.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
