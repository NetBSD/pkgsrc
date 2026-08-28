# $NetBSD: Makefile,v 1.20 2026/08/28 19:05:57 ryoon Exp $

DISTNAME=	libdvdnav-7.0.0
CATEGORIES=	multimedia
MASTER_SITES=	https://download.videolan.org/pub/videolan/libdvdnav/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	Library to navigate DVDs
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	output/meson-private/dvdnav.pc.in

.include "../../devel/meson/build.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
