# $NetBSD: Makefile,v 1.25 2004/04/26 07:10:16 fredb Exp $
#

DISTNAME=	Squeak-3.6-3
PKGNAME=	squeak-3.6.3
CATEGORIES=	lang
MASTER_SITES=	http://www-sor.inria.fr/~piumarta/squeak/unix/release/
DISTFILES=	Squeak-3.6-3.src.tar.gz	Squeak-3.6-5429.image.tar.gz
DISTFILES+=	Squeak-3.sources.tar.gz

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www-sor.inria.fr/~piumarta/squeak/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

AUTOCONF_REQD>=	2.57
AUTOMAKE_REQD=	1.4.6

BUILD_DIRS=		${WRKDIR}/build
CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/platforms/unix/config/configure
DIST_SUBDIR=		squeak
INSTALLATION_DIRS=	${WRKDIR}/build

ONLY_FOR_PLATFORM=	NetBSD-*-*

SQUEAK_CHANGES= ${DISTNAME}/usr/local/lib/squeak/Squeak3.6-5429.changes.gz
SQUEAK_IMAGE=	${DISTNAME}/usr/local/lib/squeak/Squeak3.6-5429.image.gz
SQUEAK_SOURCES=	Squeak-3/usr/local/lib/squeak/SqueakV3.sources

pre-configure:
	cd ${WRKSRC}/platforms/unix/config 				\
	    && ${SETENV} PATH=${PREFIX}/bin:${PATH} ${MAKE} configure
	${MKDIR} ${CONFIGURE_DIRS}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${SQUEAK_CHANGES} ${PREFIX}/lib/squeak/
	${INSTALL_DATA} ${WRKDIR}/${SQUEAK_IMAGE} ${PREFIX}/lib/squeak/
	${INSTALL_DATA} ${WRKDIR}/${SQUEAK_SOURCES} ${PREFIX}/lib/squeak/
	cd ${PREFIX}/lib/squeak						\
	    && ${LN} -s ${SQUEAK_CHANGES:C/.*\///} squeak.changes.gz	\
	    && ${LN} -s ${SQUEAK_IMAGE:C/.*\///} squeak.image.gz
	${INSTALL_SCRIPT} ${INSTALLATION_DIRS}/inisqueak ${PREFIX}/bin/

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
CONFIGURE_ARGS+=	--enable-mpg-mmx
.endif

.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../audio/nas/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
