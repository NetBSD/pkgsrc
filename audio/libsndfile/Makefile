# $NetBSD: Makefile,v 1.74 2017/05/17 21:51:46 he Exp $

DISTNAME=	libsndfile-1.0.28
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes

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
