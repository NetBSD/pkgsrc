# $NetBSD: Makefile,v 1.33 2007/12/12 20:42:34 wiz Exp $
#

DISTNAME=	Squeak-3.6-3
PKGNAME=	squeak-3.6.3
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://squeakvm.org/unix/release/
DISTFILES=	Squeak-3.6-3.src.tar.gz	Squeak-3.6-5429.image.tar.gz
DISTFILES+=	Squeak-3.sources.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squeakvm.org/unix/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake14

AUTOCONF_REQD=	2.57
AUTOMAKE_REQD=	1.4.6

BUILD_DIRS=		${WRKDIR}/build
CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/platforms/unix/config/configure
DIST_SUBDIR=		squeak

ONLY_FOR_PLATFORM=	NetBSD-*-*

SQUEAK_CHANGES= ${DISTNAME}/usr/local/lib/squeak/Squeak3.6-5429.changes.gz
SQUEAK_IMAGE=	${DISTNAME}/usr/local/lib/squeak/Squeak3.6-5429.image.gz
SQUEAK_SOURCES=	Squeak-3/usr/local/lib/squeak/SqueakV3.sources

INSTALLATION_DIRS=	bin lib/squeak
INSTALL_ENV+=	ROOT=${DESTDIR:Q}

pre-configure:
	cd ${WRKSRC}/platforms/unix/config 				\
	    && ${SETENV} PATH=${PREFIX}/bin:${PATH} ${MAKE} configure
	${MKDIR} ${CONFIGURE_DIRS}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${SQUEAK_CHANGES} ${DESTDIR}${PREFIX}/lib/squeak/
	${INSTALL_DATA} ${WRKDIR}/${SQUEAK_IMAGE} ${DESTDIR}${PREFIX}/lib/squeak/
	${INSTALL_DATA} ${WRKDIR}/${SQUEAK_SOURCES} ${DESTDIR}${PREFIX}/lib/squeak/
	cd ${DESTDIR}${PREFIX}/lib/squeak						\
	    && ${LN} -s ${SQUEAK_CHANGES:C/.*\///} squeak.changes.gz	\
	    && ${LN} -s ${SQUEAK_IMAGE:C/.*\///} squeak.image.gz
	${INSTALL_SCRIPT} ${WRKDIR}/build/inisqueak ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
CONFIGURE_ARGS+=	--enable-mpg-mmx
.endif

CONFIGURE_ARGS+=	--x-libraries=${X11BASE}

.include "../../audio/nas/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
