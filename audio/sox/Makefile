# $NetBSD: Makefile,v 1.72 2023/05/06 19:09:05 ryoon Exp $

DISTNAME=	sox-14.4.2
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

#USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-libltdl
CONFIGURE_ENV+=		ac_cv_func_fmemopen=no

PKGCONFIG_OVERRIDE+=	sox.pc.in

SUBST_CLASSES+=		gsm
SUBST_FILES.gsm=	configure src/gsm.c src/wav.c CMakeLists.txt
SUBST_SED.gsm=		-e "s!gsm/gsm.h!gsm.h!"
SUBST_STAGE.gsm=	pre-configure

.include "options.mk"

# failed to convert strong functions and variables: Invalid type identifier
CTF_FILES_SKIP+=	lib/libsox.so.3.0.0

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
