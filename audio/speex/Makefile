# $NetBSD: Makefile,v 1.21 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=	speex-1.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	speex.pc.in
USE_TOOLS+=		pkg-config

# previous versions of the package were called Speex
CONFLICTS=	Speex-[0-9]*

CONFIGURE_ARGS+=	--with-ogg-dir="${BUILDLINK_PREFIX.libogg}"

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=         F77=${FALSE:Q}

BUILDLINK_TRANSFORM+=	l:gnugetopt:getopt

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
