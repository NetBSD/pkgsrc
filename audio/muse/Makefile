# $NetBSD: Makefile,v 1.15 2006/01/24 07:31:55 wiz Exp $
#

DISTNAME=	MuSE-0.9
PKGNAME=	${DISTNAME:S/MuSE/muse/}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.dyne.org/muse/releases/ \
		http://www.ljudmila.org/~jaromil/muse/releases/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://muse.dyne.org/
COMMENT=	Multiple Streaming Engine

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-ncurses
CONFIGURE_ARGS+=	--disable-lubrify
CONFIGURE_ARGS+=	--enable-gtk2
LIBS+=			${LIBOSSAUDIO}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_FLAGS+=		docsdir=${PREFIX:Q}/share/doc/MuSE

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_FILES.dsp=	src/jmixer.cpp src/libmpeg/fileplayer.cc
SUBST_SED.dsp=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.dsp=	"Fixing hardcoded audio device."

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
