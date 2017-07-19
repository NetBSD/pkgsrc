# $NetBSD: Makefile,v 1.6 2017/07/19 04:01:58 ryoon Exp $

DISTNAME=	urw-fonts-2.0
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/urw-fonts/urw-fonts-2.0.tar.bz2/c5cc8237e4289fc6ebeaa296174fa504/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://download.gimp.org/pub/gimp/fonts/
COMMENT=	Standard postscript fonts (cyrillicized)
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${PKGNAME_NOREV}

URW_DINGBATS=	urw-dingbats.tar.bz2
SITES.${URW_DINGBATS}=	http://pkgs.fedoraproject.org/repo/pkgs/urw-fonts/urw-dingbats.tar.bz2/5115d797f66c7414a08b5300aae64273/

URW_SYMBOL=	urw-symbol.tar.bz2
SITES.${URW_SYMBOL}=	http://pkgs.fedoraproject.org/repo/pkgs/urw-fonts/urw-symbol.tar.bz2/efb9216f950612419874f37b63d80ae3/

#URW_TWEAKS=	urw-tweaks.tar.bz2
#SITES.${URW_TWEAKS}=	http://pkgs.fedoraproject.org/repo/pkgs/urw-fonts/urw-tweaks.tar.bz2/bf5a7e18737c3a8152f4f0c3aa6fa8fa/

DISTFILES=	${DEFAULT_DISTFILES} ${URW_DINGBATS} ${URW_SYMBOL} #${URW_TWEAKS}

WRKSRC=		${WRKDIR}/fonts
USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/urw
INSTALLATION_DIRS= share/fonts/urw

do-install:
	for dir in ${WRKSRC} ${WRKDIR}; \
	do \
	for ext in afm pfb; \
	do \
		for f in $${dir}/*.$${ext}; \
		do \
			${INSTALL_DATA} $${f} ${DESTDIR}${FONTS_DIR}; \
		done; \
	done; \
	done;

.include "../../mk/bsd.pkg.mk"
