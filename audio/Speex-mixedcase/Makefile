# $NetBSD: Makefile,v 1.2 2002/11/11 13:44:30 wiz Exp $
#

DISTNAME=	speex-1.0beta3
PKGNAME=	Speex-0.99.3
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	open-source, patent-free voice codec

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-ogg-dir="${BUILDLINK_PREFIX.libogg}"

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
