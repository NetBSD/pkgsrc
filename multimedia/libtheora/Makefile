# $NetBSD: Makefile,v 1.6 2005/04/11 21:46:42 tv Exp $
#

DISTNAME=	libtheora-1.0alpha4
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/theora/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming

GNU_CONFIGURE=	YES
PKGCONFIG_OVERRIDE=	theora.pc.in
USE_LIBTOOL=	YES

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
