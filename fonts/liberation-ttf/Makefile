# $NetBSD: Makefile,v 1.3 2008/12/13 15:34:17 ahoka Exp $
#

DISTNAME=	liberation-fonts-1.04
PKGNAME=	${DISTNAME:S/fonts/ttf/}
CATEGORIES=	fonts

# The official repo is https only,
# so we have to fetch from this strange URL.
#
LF_HASH=	4846797ef0fc70b0cbaede2514677c58
LF_BASEURL=	http://cvs.fedoraproject.org/repo/pkgs/liberation-fonts
MASTER_SITES=	${LF_BASEURL}/${DISTNAME}.tar.gz/${LF_HASH}/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.redhat.com/promo/fonts/
COMMENT=	TrueType fonts from RedHat

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/ttf/fonts/}

DOCDIR=		${PREFIX}/share/doc/liberation-ttf
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIR.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/License.txt \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
