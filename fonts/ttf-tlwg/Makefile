# $NetBSD: Makefile,v 1.3 2015/08/17 18:09:07 leot Exp $

DISTNAME=	ttf-tlwg-0.6.1
CATEGORIES=	fonts
MASTER_SITES=	ftp://linux.thai.net/pub/thailinux/software/thai-ttf/ \
		http://linux.thai.net/pub/thailinux/software/thai-ttf/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/thaifonts-scalable
COMMENT=	Thai fonts in TTF format
LICENSE=	gnu-gpl-v2 AND vera-ttf-license

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR} share/fontconfig/conf.avail

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/etc/fonts/conf.avail/* \
		${DESTDIR}${PREFIX}/share/fontconfig/conf.avail

.include "../../mk/bsd.pkg.mk"
