# $NetBSD: Makefile,v 1.28 2021/01/24 16:12:51 nia Exp $

DISTNAME=	libsamplerate-0.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsndfile/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libsndfile.github.io/libsamplerate/
COMMENT=	Sample rate converter library
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/samplerate.pc.in

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
