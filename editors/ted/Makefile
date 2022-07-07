# $NetBSD: Makefile,v 1.69 2022/07/07 20:17:47 nia Exp $

DISTNAME=	ted-2.23.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	editors
MASTER_SITES=	https://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nllgg.nl/Ted/
COMMENT=	X11 based WordPad-like word processor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/Ted-${PKGVERSION_NOREV}

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/dfa
INFODIR=	${PREFIX}/share/doc/Ted

LDFLAGS.SunOS+=		-liconv
LDFLAGS.Darwin+=	-liconv

MAKE_FLAGS+=	CONFIGURE_OPTIONS=--x-libraries=${X11BASE}/lib\ --with-MOTIF

MAKE_ENV+=	${CONFIGURE_ENV}
CPPFLAGS+=	-DPKGDIR=\"${PREFIX}\"
CPPFLAGS+=	-DAFMDIR=\"${AFMDIR}\"
CPPFLAGS+=	-DINDDIR=\"${INDDIR}\"
CPPFLAGS+=	-DDOCUMENT_DIR=\"${INFODIR}\"

BUILD_TARGET=	compile.shared

INSTALLATION_DIRS=	bin ${AFMDIR} ${INDDIR} ${INFODIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-extract:
	cd ${WRKSRC} && tar xf tedPackage/TedDatadir.tar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${DESTDIR}${PREFIX}/bin/Ted
	${INSTALL_MAN} ${WRKSRC}/doc/Ted.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/Ted.1
	${INSTALL_DATA} ${WRKSRC}/afm/*.afm ${DESTDIR}${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/TedDocument-en_US.rtf ${DESTDIR}${INFODIR}
	${INSTALL_DATA} ${FILESDIR}/Ted.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Ted.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/dfa/*.dfa \
		${DESTDIR}${INDDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
