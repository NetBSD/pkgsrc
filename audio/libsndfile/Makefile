# $NetBSD: Makefile,v 1.56 2009/12/15 11:08:38 wiz Exp $

DISTNAME=	libsndfile-1.0.21
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		vorbis
SUBST_FILES.vorbis=	configure
SUBST_SED.vorbis=	-e "s/1\.2\.1/1.2.0/g"
SUBST_STAGE.vorbis=	pre-configure
SUBST_MESSAGE.vorbis=	Allowing libvorbis-1.2.0.

# This package compiles with gcc2, but its configure script doesn't know that
CONFIGURE_ENV+=		ac_cv_c_struct_hack=yes

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_PASSTHRU_DIRS+=	/Developer
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
CXXFLAGS+=		-features=extensions
.endif

.include "../../audio/flac/buildlink3.mk"
#BUILDLINK_API_DEPENDS.libvorbis+=	libvorbis>=1.2.1
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1.3
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
