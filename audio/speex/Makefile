# $NetBSD: Makefile,v 1.11 2004/04/12 23:15:01 salo Exp $
#

DISTNAME=	speex-1.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

# previous versions of the package were called Speex
CONFLICTS=	Speex-[0-9]*

CONFIGURE_ARGS+=	--with-ogg-dir="${BUILDLINK_PREFIX.libogg}"

.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
