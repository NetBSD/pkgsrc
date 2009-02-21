# $NetBSD: Makefile,v 1.20 2009/02/21 13:22:43 wiz Exp $
#

DISTNAME=	libsamplerate-0.1.4
PKGREVISION=	1
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
