# $NetBSD: Makefile,v 1.57 2012/10/02 23:48:09 asau Exp $

DISTNAME=	sox-14.4.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

#USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gomp
CONFIGURE_ARGS+=	--without-libltdl
CONFIGURE_ENV+=		ac_cv_func_fmemopen=no

PKGCONFIG_OVERRIDE+=	sox.pc.in

SUBST_CLASSES+=		gsm
SUBST_FILES.gsm=	configure src/gsm.c src/wav.c CMakeLists.txt
SUBST_SED.gsm=		-e "s!gsm/gsm.h!gsm.h!"
SUBST_STAGE.gsm=	pre-configure

post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/lib/sox

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
