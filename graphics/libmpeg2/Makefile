# $NetBSD: Makefile,v 1.5 2004/01/24 15:46:44 grant Exp $

DISTNAME=	mpeg2dec-0.4.0
PKGNAME=	libmpeg2-0.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	library for decoding mpeg-2 and mpeg-1 video streams

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

PKGCONFIG_OVERRIDE+=    libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=    libmpeg2/libmpeg2.pc.in

CONFIGURE_ARGS=	--enable-shared

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
