# $NetBSD: Makefile,v 1.40 2007/02/22 23:23:03 wiz Exp $

DISTNAME=	sox-13.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/} \
		http://www.cnpbagwell.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		lrf
SUBST_FILES.lrf=	src/libst-config.in
SUBST_SED.lrf=		-e "s!@LRF@!"${LINKER_RPATH_FLAG:Q}"!"
SUBST_STAGE.lrf=	pre-configure

SUBST_CLASSES+=		gsm
SUBST_FILES.gsm=	configure src/gsm.c src/wav.c
SUBST_SED.gsm=		-e "s!gsm/gsm.h!gsm.h!"
SUBST_STAGE.gsm=	pre-configure

# needs obsolete FLAC API
#.include "../../audio/flac/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
