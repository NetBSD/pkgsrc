# $NetBSD: Makefile,v 1.16 2007/06/23 08:06:00 minskim Exp $
#

DISTNAME=	libsamplerate-0.1.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/SRC/
COMMENT=	Sample rate converter library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config
PKGCONFIG_OVERRIDE+= ${WRKSRC}/samplerate.pc.in

.if exists(/Developer/Headers/FlatCarbon)
BUILDLINK_PASSTHRU_DIRS+=		/Developer/Headers/FlatCarbon
.endif

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
