# $NetBSD: Makefile,v 1.1.1.1 2003/08/05 07:13:42 wulf Exp $

DISTNAME=	mpeg2dec-${PKGNAME:S/libmpeg2-//}
PKGNAME=	libmpeg2-20030612
CATEGORIES=	graphics
MASTER_SITES=	http://www.videolan.org/pub/vlc/0.6.1/contrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	library for decoding mpeg-2 and mpeg-1 video streams

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

CONFIGURE_ARGS=	--enable-shared

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
