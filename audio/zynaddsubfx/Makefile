# $NetBSD: Makefile,v 1.6 2022/06/28 11:30:58 wiz Exp $

DISTNAME=	zynaddsubfx-3.0.5
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zynaddsubfx/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zynaddsubfx.sourceforge.io/
COMMENT=	Software synthesizer
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.8

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
PLIST.oss=		yes
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/Misc/Config.cpp
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

CHECK_PORTABILITY_SKIP+=	doc/bash-completion/zynaddsubfx.in

.include "options.mk"

post-install:
.if empty(PKG_OPTIONS:Malsa)
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/zynaddsubfx-alsa.desktop
.endif
.if empty(PKG_OPTIONS:Mjack)
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/zynaddsubfx-jack-multi.desktop
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/zynaddsubfx-jack.desktop
.endif
.if ${OSS_TYPE} == "none"
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/zynaddsubfx-oss.desktop
.endif

.include "../../audio/dssi/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/mxml/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
