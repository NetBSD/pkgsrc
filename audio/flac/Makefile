# $NetBSD: Makefile,v 1.1.1.1 2001/07/23 13:28:26 wiz Exp $
#

DISTNAME=		flac-1.0-src
PKGNAME=		flac-1.0
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		free lossless audio codec

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-*-i386} != ""
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-configure:
	(cd ${WRKSRC}/src/libFLAC/ia32 && \
		${MV} Makefile.am Makefile.am.orig && \
		${CP} Makefile.am.libtool-1.4b Makefile.am)
	(cd ${WRKSRC} && ${LOCALBASE}/bin/automake)

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/src/flac/flac \
		${WRKSRC}/src/metaflac/metaflac ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/include/FLAC
	${INSTALL_DATA} ${WRKSRC}/include/FLAC/*.h ${PREFIX}/include/FLAC
	${LIBTOOL} ${INSTALL_DATA} -p ${WRKSRC}/src/libFLAC/libFLAC.la \
		${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/flac.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flac
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flac/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flac/ru
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.gif \
		${WRKSRC}/doc/images/*.jpg \
		${PREFIX}/share/doc/flac/images
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/flac
	${INSTALL_DATA} ${WRKSRC}/doc/ru/*.html ${PREFIX}/share/doc/flac/ru

.include "../../mk/bsd.pkg.mk"
