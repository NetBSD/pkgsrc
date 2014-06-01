# $NetBSD: Makefile,v 1.6 2014/06/01 16:35:37 wiz Exp $
#

DISTNAME=	uni-vga
PKGNAME=	${DISTNAME}-1
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.inp.nsk.su/~bolkhov/files/fonts/univga/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mw+pkgsrc@wzff.de
HOMEPAGE=	http://www.inp.nsk.su/~bolkhov/files/fonts/univga/
COMMENT=	Monospaced Unicode font based on the original IBM VGA font
LICENSE=	mit

USE_TOOLS+=		bdftopcf gzip

FONTDIR=		${PREFIX}/share/fonts/X11/uni-vga
FONTS_DIRS.x11+=	${FONTDIR}
WRKSRC=			${WRKDIR}/uni_vga

INSTALLATION_DIRS=	${FONTDIR}

do-build:
	bdftopcf -o ${WRKSRC}/u_vga16.pcf ${WRKSRC}/u_vga16.bdf
	${TOOLS_PATH.gzip} -9 ${WRKSRC}/u_vga16.pcf

do-install:
	${INSTALL_DATA} ${WRKSRC}/u_vga16.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
