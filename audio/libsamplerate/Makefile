# $NetBSD: Makefile,v 1.21 2009/02/25 19:35:46 drochner Exp $
#

DISTNAME=	libsamplerate-0.1.7
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/SRC/
COMMENT=	Sample rate converter library

PKG_DESTDIR_SUPPORT=	user-destdir

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
