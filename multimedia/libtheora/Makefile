# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 13:47:43 jmmv Exp $
#

DISTNAME=	libtheora-1.0alpha3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.theora.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
