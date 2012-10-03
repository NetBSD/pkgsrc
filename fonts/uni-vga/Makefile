# $NetBSD: Makefile,v 1.4 2012/10/03 18:28:32 asau Exp $
#

DISTNAME=	uni-vga
PKGNAME=	${DISTNAME}-1
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.inp.nsk.su/~bolkhov/files/fonts/univga/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mw+pkgsrc@wzff.de
HOMEPAGE=	http://www.inp.nsk.su/~bolkhov/files/fonts/univga/
COMMENT=	Monospaced Unicode font based on the original IBM VGA font
LICENSE=	mit

USE_TOOLS+=		bdftopcf gzip

FONTDIR=		${PREFIX}/lib/X11/fonts/uni-vga
FONTS_DIRS.x11+=	${FONTDIR}
WRKSRC=			${WRKDIR}/uni_vga

INSTALLATION_DIRS=	${FONTDIR}

do-build:
	${TOOLS_PATH.bdftopcf} -o ${WRKSRC}/u_vga16.pcf ${WRKSRC}/u_vga16.bdf
	${TOOLS_PATH.gzip} -9 ${WRKSRC}/u_vga16.pcf

do-install:
	${INSTALL_DATA} ${WRKSRC}/u_vga16.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
