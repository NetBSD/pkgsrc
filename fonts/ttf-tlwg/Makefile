# $NetBSD: Makefile,v 1.4 2015/08/17 18:33:08 leot Exp $

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
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-01-tlwg-kinnari.conf \
		${PKG_SYSCONFDIR}/conf.d/64-01-tlwg-kinnari.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-02-tlwg-norasi.conf \
		${PKG_SYSCONFDIR}/conf.d/64-02-tlwg-norasi.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-11-tlwg-waree.conf \
		${PKG_SYSCONFDIR}/conf.d/64-11-tlwg-waree.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-12-tlwg-loma.conf \
		${PKG_SYSCONFDIR}/conf.d/64-12-tlwg-loma.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-13-tlwg-garuda.conf \
		${PKG_SYSCONFDIR}/conf.d/64-13-tlwg-garuda.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-14-tlwg-umpush.conf \
		${PKG_SYSCONFDIR}/conf.d/64-14-tlwg-umpush.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-15-laksaman.conf \
		${PKG_SYSCONFDIR}/conf.d/64-15-laksaman.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-21-tlwg-typo.conf \
		${PKG_SYSCONFDIR}/conf.d/64-21-tlwg-typo.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-22-tlwg-typist.conf \
		${PKG_SYSCONFDIR}/conf.d/64-22-tlwg-typist.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/64-23-tlwg-mono.conf \
		${PKG_SYSCONFDIR}/conf.d/64-23-tlwg-mono.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-tlwg-garuda-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-tlwg-garuda-synthetic.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-tlwg-kinnari-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-tlwg-kinnari-synthetic.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-tlwg-laksaman-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-tlwg-laksaman-synthetic.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-tlwg-loma-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-tlwg-loma-synthetic.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-tlwg-umpush-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-tlwg-umpush-synthetic.conf
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/89-tlwg-waree-synthetic.conf \
		${PKG_SYSCONFDIR}/conf.d/89-tlwg-waree-synthetic.conf

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/etc/fonts/conf.avail/* \
		${DESTDIR}${PREFIX}/share/fontconfig/conf.avail

.include "../../mk/bsd.pkg.mk"
