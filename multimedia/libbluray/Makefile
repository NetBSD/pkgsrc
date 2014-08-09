# $NetBSD: Makefile,v 1.1 2014/08/09 20:19:35 wiz Exp $

DISTNAME=	libbluray-0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/libbluray/0.6.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/libbluray.html
COMMENT=	Library for Blu-Ray Discs playback for media players
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libbluray.pc.in

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
