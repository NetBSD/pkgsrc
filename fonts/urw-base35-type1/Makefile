# $NetBSD: Makefile,v 1.1 2024/05/03 20:38:35 ryoon Exp $

DISTNAME=	gs400fn1
PKGNAME=	urw-base35-type1-4.00
CATEGORIES=	fonts
MASTER_SITES=	ftp://tug.org/historic/fonts/base35/
EXTRACT_SUFX=	.zip
DISTFILES=	${DEFAULT_DISTFILES} gs400fn2${EXTRACT_SUFX}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://tug.org/fonts/lppl-urw.txt
COMMENT=	PostScript Level 1 and 2 fonts in Type 1 format
LICENSE=	lppl-1.3c

WRKSRC=			${WRKDIR}/fonts
USE_LANGUAGES=		# none
NO_BUILD=		yes
FONTS_DIR.type1=	share/fonts/urw-base35-lppl
INSTALLATION_DIRS=	${FONTS_DIR.type1}

do-install:
.for prfx in a b c d n p s z
.  for sufx in afm pfb
	${INSTALL_DATA} ${WRKSRC}/${prfx}0*.${sufx} ${DESTDIR}${PREFIX}/${FONTS_DIR.type1}
.  endfor
.endfor

.include "../../mk/bsd.pkg.mk"
