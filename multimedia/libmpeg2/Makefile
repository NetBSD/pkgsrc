# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:02 tv Exp $

DISTNAME=	mpeg2dec-0.4.0
PKGNAME=	libmpeg2-0.4.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
