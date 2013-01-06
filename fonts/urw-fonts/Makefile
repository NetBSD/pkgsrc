# $NetBSD: Makefile,v 1.3 2013/01/06 23:19:11 wiz Exp $
#

DISTNAME=	urw-fonts-1.0.7pre44
CATEGORIES=	fonts
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/urw-fonts/urw-fonts-1.0.7pre44.tar.bz2/51c6c2690593cd9bd92f197a6f2ff8bd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	ftp://ftp.gimp.org/pub/gimp/fonts/
COMMENT=	Standard postscript fonts (cyrillicized)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
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
