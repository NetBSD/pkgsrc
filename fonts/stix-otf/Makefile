# $NetBSD: Makefile,v 1.1 2016/02/02 17:53:54 nros Exp $

stixver=	1.1.0
DISTNAME=	STIXv${stixver}
PKGNAME=	stix-otf-${stixver}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stixfonts/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stixfonts.org/
COMMENT=	OpenType Unicode maths fonts
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/OTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/doc/${PKGNAME} share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/Fonts/STIX-General/*.otf \
		${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/Fonts/STIX-Word/*.otf \
		${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/License/*.pdf \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/*.pdf \
                ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}


.include "../../mk/bsd.pkg.mk"
