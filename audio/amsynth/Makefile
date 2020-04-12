# $NetBSD: Makefile,v 1.2 2020/04/12 15:21:44 nia Exp $

DISTNAME=	amsynth-1.9.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=amsynth/}
GITHUB_PROJECT=	amsynth
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://amsynth.github.io/
COMMENT=	Software synth with a subtractive synthesizer topology
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_TOOLS+=	perl pkg-config gmake
USE_TOOLS+=	intltool msgfmt msgmerge xgettext

# XXX: this should be an option.
CONFIGURE_ARGS+=	--without-pandoc

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LIBS+=			${LIBOSSAUDIO}
CONFIGURE_ARGS=		--with-oss
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	data/rc
SUBST_FILES.oss+=	src/Configuration.cpp
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_SED.oss+=		-e "s,/dev/midi,${DEVOSSMIDI},g"
.else
CONFIGURE_ARGS+=	--without-oss
.endif

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		sr
SUBST_STAGE.sr=		pre-configure
SUBST_MESSAGE.sr=	Setting a better default sample rate.
SUBST_FILES.sr+=	data/rc
SUBST_FILES.sr+=	src/Configuration.cpp
SUBST_SED.sr+=		-e "s,44100,48000,g"
.endif

.include "options.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
