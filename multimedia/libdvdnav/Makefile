# $NetBSD: Makefile,v 1.17 2020/03/28 17:43:37 nia Exp $

DISTNAME=	libdvdnav-6.1.0
CATEGORIES=	multimedia
MASTER_SITES=	https://download.videolan.org/pub/videolan/libdvdnav/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	Library to navigate DVDs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99

PKGCONFIG_OVERRIDE=	misc/dvdnav.pc.in

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
