# $NetBSD: Makefile,v 1.3 2014/05/05 00:47:49 ryoon Exp $

DISTNAME=	free42
PKGVERSION=	1.4.78
PKGNAME=	${DISTNAME}-${PKGVERSION}
PKGREVISION=	1
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	emulators
MASTER_SITES=	http://thomasokken.com/free42/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thomasokken.com/free42/
COMMENT=	HP42S Calculator Simulator
LICENSE=	gnu-gpl-v2

#WRKSRC=		${WRKDIR}/free42/gtk/
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c++
BUILD_DIRS=	gtk

.include "options.mk"

BUILD_TARGET=	free42${VARIANT}

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CXXFLAGS+=	-DNO_SINCOS
.elif (${OPSYS} == Linux)
MAKE_ENV+=	AUDIO_ALSA=1
.endif

INSTALLATION_DIRS+= bin
INSTALLATION_DIRS+= share/doc/free42

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/${BUILD_TARGET} \
		${DESTDIR}/${PREFIX}/bin/free42
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}/${PREFIX}/share/doc/free42
	${INSTALL_DATA} ${WRKSRC}/${BUILD_DIRS}/README \
		${DESTDIR}/${PREFIX}/share/doc/free42/README.gtk

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
