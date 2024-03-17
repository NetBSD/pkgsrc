# $NetBSD: Makefile,v 1.34 2024/03/17 12:49:12 nia Exp $

DISTNAME=	libsamplerate-0.2.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsndfile/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libsndfile.github.io/libsamplerate/
COMMENT=	Sample rate converter library
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	samplerate.pc.in

# Avoid building examples, which read into OS-specific audio APIs
# and may fail on some older platforms.
# This doesn't affect anything we actually care about (e.g. tests)
MAKE_FLAGS+=		noinst_PROGRAMS=

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
