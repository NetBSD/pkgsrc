# $NetBSD: Makefile,v 1.36 2008/02/06 18:45:32 reed Exp $
#

DISTNAME=	Squeak-3.9-8
PKGNAME=	squeak-3.9.8
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://ftp.squeak.org/3.9/unix-linux/
DISTFILES=	Squeak-3.9-8.src.tar.gz
DISTFILES+=	Squeak3.9-final-7067.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squeakvm.org/unix/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake14 gmake gzip

AUTOCONF_REQD=	2.57
AUTOMAKE_REQD=	1.4.6

BUILD_DIRS=		${WRKDIR}/build
CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/platforms/unix/config/configure
DIST_SUBDIR=		squeak

SQUEAK_CHANGES= Squeak3.9-final-7067/Squeak3.9-final-7067.changes.gz
SQUEAK_IMAGE=	Squeak3.9-final-7067/Squeak3.9-final-7067.image.gz
SQUEAK_SOURCES=	Squeak3.9-final-7067/SqueakV39.sources

INSTALLATION_DIRS=	bin lib/squeak
INSTALL_ENV+=	ROOT=${DESTDIR:Q}

post-extract:
	${GZIP_CMD} ${WRKDIR}/${SQUEAK_IMAGE:S/.gz$//W}
	${GZIP_CMD} ${WRKDIR}/${SQUEAK_CHANGES:S/.gz$//W}

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
