# $NetBSD: Makefile,v 1.69 2016/02/25 10:15:45 jperkin Exp $

DISTNAME=	libsndfile-1.0.26
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes

# This package compiles with gcc2, but its configure script doesn't know that
CONFIGURE_ENV+=		ac_cv_c_struct_hack=yes

TEST_TARGET=		check

.include "options.mk"

OPSYSVARS+=		BUILDLINK_PASSTHRU_DIRS

BUILDLINK_PASSTHRU_DIRS.Darwin+=	/Developer

.if !empty(PKGSRC_COMPILER:Msunpro)
CXXFLAGS+=		-features=extensions
.endif

.include "../../audio/flac/buildlink3.mk"
#BUILDLINK_API_DEPENDS.libvorbis+=	libvorbis>=1.2.1
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1.3
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
