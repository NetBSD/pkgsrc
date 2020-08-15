# $NetBSD: Makefile,v 1.77 2020/08/15 23:36:38 nia Exp $

DISTNAME=	libsndfile-1.0.29
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=erikd/}
GITHUB_PROJECT=	libsndfile
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	autogen-[0-9]*:../../devel/autogen

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autogen autoconf autoreconf automake pkg-config
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "options.mk"

OPSYSVARS+=		BUILDLINK_PASSTHRU_DIRS

BUILDLINK_PASSTHRU_DIRS.Darwin+=	/Developer

.if !empty(PKGSRC_COMPILER:Msunpro)
CXXFLAGS+=		-features=extensions
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1.3
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
