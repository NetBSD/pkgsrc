# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:03 tv Exp $
#

DISTNAME=	libtheora-1.0alpha3
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.theora.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
