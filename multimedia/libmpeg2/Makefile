# $NetBSD: Makefile,v 1.4 2005/03/23 16:27:02 wiz Exp $

DISTNAME=	mpeg2dec-0.4.0b
PKGNAME=	libmpeg2-0.4.0b
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# remove on next update, only needed for 0.4.0b
WRKSRC=		${WRKDIR}/mpeg2dec-0.4.0

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes

PKGCONFIG_OVERRIDE+=    libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=    libmpeg2/libmpeg2.pc.in

CONFIGURE_ARGS=	--enable-shared

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
