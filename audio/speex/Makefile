# $NetBSD: Makefile,v 1.3 2003/06/05 13:18:10 wiz Exp $
#

DISTNAME=	speex-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	open-source, patent-free voice codec

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

# previous versions of the package were called Speex
CONFLICTS=	Speex-[0-9]*

CONFIGURE_ARGS+=	--with-ogg-dir="${BUILDLINK_PREFIX.libogg}"

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
