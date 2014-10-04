# $NetBSD: Makefile,v 1.12 2014/10/04 12:44:45 wiz Exp $

DISTNAME=	libdvdnav-5.0.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/libdvdnav/5.0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	Library to navigate DVDs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	misc/dvdnav.pc.in

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
