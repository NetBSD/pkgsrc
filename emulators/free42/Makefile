# $NetBSD: Makefile,v 1.21 2020/03/16 00:21:07 tnn Exp $

DISTNAME=	free42
PKGNAME=	${DISTNAME}-1.4.78
PKGREVISION=	13
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	emulators
#MASTER_SITES=	http://thomasokken.com/free42/download/
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thomasokken.com/free42/
COMMENT=	HP42S Calculator Simulator
LICENSE=	gnu-gpl-v2

#WRKSRC=	${WRKDIR}/free42/gtk/
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c++03
BUILD_DIRS=	gtk

.include "options.mk"

BUILD_TARGET=	free42${VARIANT}

CXXFLAGS.NetBSD+=	-DNO_SINCOS

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/free42

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/${BUILD_TARGET} \
		${DESTDIR}/${PREFIX}/bin/free42
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}/${PREFIX}/share/doc/free42
	${INSTALL_DATA} ${WRKSRC}/${BUILD_DIRS}/README \
		${DESTDIR}/${PREFIX}/share/doc/free42/README.gtk

.if ${OPSYS} == "Linux"
MAKE_ENV+=	AUDIO_ALSA=1
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
