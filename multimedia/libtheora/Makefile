# $NetBSD: Makefile,v 1.13 2006/11/05 17:25:35 joerg Exp $
#

DISTNAME=	libtheora-1.0alpha7
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/theora/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	theora.pc.in
USE_LIBTOOL=		YES
TEST_TARGET=		check

CONFIGURE_ARGS+=	HAVE_DOXYGEN=false

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
