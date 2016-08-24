# $NetBSD: Makefile,v 1.5 2016/08/24 10:29:50 wiz Exp $

DISTNAME=	urw-fonts-2.0
CATEGORIES=	fonts
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/urw-fonts/urw-fonts-2.0.tar.bz2/c5cc8237e4289fc6ebeaa296174fa504/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://download.gimp.org/pub/gimp/fonts/
COMMENT=	Standard postscript fonts (cyrillicized)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/fonts
USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/urw
INSTALLATION_DIRS= share/fonts/urw

do-install:
	for ext in afm pfb; \
	do \
		for f in ${WRKSRC}/*.$${ext}; \
		do \
			${INSTALL_DATA} $${f} ${DESTDIR}${FONTS_DIR}; \
		done; \
	done

.include "../../mk/bsd.pkg.mk"
