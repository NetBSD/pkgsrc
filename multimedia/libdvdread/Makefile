# $NetBSD: Makefile,v 1.38 2026/09/22 20:55:39 chuck Exp $

DISTNAME=	libdvdread-7.1.1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdvdread/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	DVD access library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	misc/dvdread.pc.in

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
