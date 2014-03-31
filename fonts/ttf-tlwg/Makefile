# $NetBSD: Makefile,v 1.1 2014/03/31 08:11:14 wiz Exp $

DISTNAME=	ttf-tlwg-0.6.0
CATEGORIES=	fonts
MASTER_SITES=	ftp://linux.thai.net/pub/thailinux/software/thai-ttf/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/thaifonts-scalable
COMMENT=	Thai fonts in TTF format
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf= ${FONTDIR}
PKG_SYSCONFSUBDIR=	fontconfig
CONF_FILES=	${PREFIX}/share/fontconfig/conf.avail/64-ttf-thai-tlwg.conf \
		${PKG_SYSCONFDIR}/conf.d/64-ttf-thai-tlwg.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-ttf-thai-tlwg-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-ttf-thai-tlwg-synthetic.conf
INSTALLATION_DIRS=	${FONTDIR} share/fontconfig/conf.avail

do-build:

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/etc/fonts/conf.avail/* \
		${DESTDIR}${PREFIX}/share/fontconfig/conf.avail

.include "../../mk/bsd.pkg.mk"
