# $NetBSD: Makefile,v 1.2 2002/03/05 23:29:08 skrll Exp $
#

DISTNAME=		flac-1.0-src
PKGNAME=		flac-1.0
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		free lossless audio codec

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
		${MV} Makefile.in Makefile.in.orig && \
		${CP} Makefile.in.libtool-1.4b Makefile.in)

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
