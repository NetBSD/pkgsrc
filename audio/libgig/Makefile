# $NetBSD: Makefile,v 1.2 2022/03/28 10:43:35 tnn Exp $

DISTNAME=	libgig-4.2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://download.linuxsampler.org/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linuxsampler.org/libgig/
COMMENT=	C++ library for working with sampler file formats
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gig.pc.in
PKGCONFIG_OVERRIDE+=	akai.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
