# $NetBSD: Makefile,v 1.52 2009/06/08 09:30:17 tron Exp $

DISTNAME=	libsndfile-1.0.20
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
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

.include "../../audio/flac/buildlink3.mk"
#BUILDLINK_API_DEPENDS.libvorbis+=	libvorbis>=1.2.1
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1.3
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
