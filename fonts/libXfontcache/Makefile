# $NetBSD: Makefile,v 1.3 2017/09/16 19:26:56 wiz Exp $

DISTNAME=	libXfontcache-1.0.5
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X-TrueType font cache extension client library
LICENSE=	2-clause-bsd AND x11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	xfontcache.pc.in

.include "../../x11/fontcacheproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
