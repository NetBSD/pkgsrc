# $NetBSD: Makefile,v 1.7 2017/09/06 09:03:01 wiz Exp $

DISTNAME=	ttf-tlwg-${TLWG_VERSION}
CATEGORIES=	fonts

MASTER_SITES=	${MASTER_SITE_GITHUB:=tlwg/}
GITHUB_PROJECT=	fonts-tlwg
GITHUB_RELEASE=	v${TLWG_VERSION}
EXTRACT_SUFX=	.tar.xz

TLWG_VERSION=	0.6.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/projects/thaifonts-scalable
COMMENT=	Thai fonts in TTF format
LICENSE=	gnu-gpl-v2 AND vera-ttf-license

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR} share/fontconfig/conf.avail

TMPLDIR=	${PREFIX}/share/fontconfig/conf.avail
MAKE_DIRS+=	${PKG_SYSCONFDIR}/conf.d

TLWG_STDCONF=	64-01-tlwg-kinnari.conf \
		64-02-tlwg-norasi.conf \
		64-10-tlwg-loma.conf \
		64-11-tlwg-waree.conf \
		64-13-tlwg-garuda.conf \
		64-14-tlwg-umpush.conf \
		64-15-laksaman.conf \
		64-21-tlwg-typo.conf \
		64-22-tlwg-typist.conf \
		64-23-tlwg-mono.conf \
		89-tlwg-garuda-synthetic.conf \
		89-tlwg-kinnari-synthetic.conf \
		89-tlwg-laksaman-synthetic.conf \
		89-tlwg-umpush-synthetic.conf

.for f in ${TLWG_STDCONF}
CONF_FILES+=	${TMPLDIR}/${f} ${PKG_SYSCONFDIR}/conf.d/${f}
.endfor

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/etc/fonts/conf.avail/* \
		${DESTDIR}${PREFIX}/share/fontconfig/conf.avail

.include "../../mk/bsd.pkg.mk"
