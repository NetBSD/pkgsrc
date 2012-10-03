# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:32 asau Exp $
#

DISTNAME=	urw-fonts
PKGNAME=	urw-fonts-1
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gimp.org/pub/gimp/fonts/
COMMENT=	Standard postscript fonts
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/URW
USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/urw
INSTALLATION_DIRS= share/fonts/urw

do-install:
	for ext in afm pfb pfm; \
	do \
		for f in ${WRKSRC}/*.$${ext}; \
		do \
			${INSTALL_DATA} $${f} ${DESTDIR}${FONTS_DIR}; \
		done; \
	done

.include "../../mk/bsd.pkg.mk"
