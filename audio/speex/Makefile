# $NetBSD: Makefile,v 1.12 2004/07/23 15:48:47 wiz Exp $
#

DISTNAME=	speex-1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	speex.pc.in

# previous versions of the package were called Speex
CONFLICTS=	Speex-[0-9]*

CONFIGURE_ARGS+=	--with-ogg-dir="${BUILDLINK_PREFIX.libogg}"

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
