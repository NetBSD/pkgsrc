# $NetBSD: Makefile,v 1.9 2005/07/21 16:29:54 wiz Exp $

DISTNAME=	mpeg2dec-0.4.0b
PKGNAME=	libmpeg2-0.4.0b
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# remove on next update, only needed for 0.4.0b
WRKSRC=		${WRKDIR}/mpeg2dec-0.4.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=    libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=    libmpeg2/libmpeg2.pc.in

CONFIGURE_ARGS+=	--enable-shared

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
