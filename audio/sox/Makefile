# $NetBSD: Makefile,v 1.48 2009/02/21 13:22:43 wiz Exp $

DISTNAME=	sox-14.0.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
#USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		gsm
SUBST_FILES.gsm=	configure src/gsm.c src/wav.c CMakeLists.txt
SUBST_SED.gsm=		-e "s!gsm/gsm.h!gsm.h!"
SUBST_STAGE.gsm=	pre-configure

post-install:
	-${RMDIR} ${DESTDIR}${PREFIX}/lib/sox

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
