# $NetBSD: Makefile,v 1.1.1.1 2003/03/24 08:58:53 wiz Exp $
#

DISTNAME=	speex-1.0rc3
PKGNAME=	speex-0.99.5
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
