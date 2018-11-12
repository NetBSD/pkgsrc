# $NetBSD: Makefile,v 1.33 2018/11/12 03:52:01 ryoon Exp $
#

DISTNAME=	Nestopia140src
PKGNAME=	nestopia-1.40h
PKGREVISION=	27
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nestopia/}
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} nst140_lnx_release_h.zip

SITES.nst140_lnx_release_h.zip=	http://rbelmont.mameworld.info/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rbelmont.mameworld.info/?page_id=200
COMMENT=	Portable, very accurate NES emulator with UNIF support

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

SUBST_CLASSES+=		oss
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_FILES.oss=	source/linux/oss.cpp
SUBST_MESSAGE.oss=	Fixing path to OSS device.
SUBST_STAGE.oss=	pre-build

INSTALLATION_DIRS=	bin share/doc/nestopia share/examples/nestopia

pre-patch:
	for f in ${WRKSRC}/source/core/NstMemory.hpp; do	\
		${TR} -d '\r' < $${f} > $${f}.new;		\
		${MV} $${f}.new $${f};				\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nst ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.Linux \
		${DESTDIR}${PREFIX}/share/doc/nestopia
	${INSTALL_DATA} ${WRKSRC}/readme.html \
		${DESTDIR}${PREFIX}/share/doc/nestopia
	${INSTALL_DATA} ${WRKSRC}/NstDatabase.xml \
		${DESTDIR}${PREFIX}/share/examples/nestopia
	${INSTALL_DATA} ${WRKSRC}/nstcontrols \
		${DESTDIR}${PREFIX}/share/examples/nestopia

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
