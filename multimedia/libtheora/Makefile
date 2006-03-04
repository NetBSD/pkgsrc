# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:15 jlam Exp $
#

DISTNAME=	libtheora-1.0alpha5
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/theora/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	theora.pc.in
USE_LIBTOOL=		YES
TEST_TARGET=		check

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
