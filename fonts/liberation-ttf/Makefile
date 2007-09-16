# $NetBSD: Makefile,v 1.1.1.1 2007/09/16 15:40:05 wiz Exp $
#

DISTNAME=	liberation-fonts-ttf-3
PKGNAME=	liberation-ttf-0.2
CATEGORIES=	fonts
MASTER_SITES=	http://www.redhat.com/f/fonts/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.redhat.com/promo/fonts/
COMMENT=	TrueType fonts from RedHat

NO_BUILD=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/ttf/fonts/}

DOCDIR=		${PREFIX}/share/doc/liberation-ttf
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIR.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/License.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
