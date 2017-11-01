# $NetBSD: Makefile,v 1.15 2017/11/01 05:17:06 maya Exp $

DISTNAME=	liberation-fonts-ttf-2.00.1
PKGNAME=	${DISTNAME:S/-fonts//}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	https://releases.pagure.org/liberation-fonts/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.redhat.com/promo/fonts/
COMMENT=	TrueType fonts from RedHat
LICENSE=	ofl-v1.1

NO_BUILD=	yes
NO_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

do-install:
	set -e; \
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/ChangeLog \
		${WRKSRC}/LICENSE ${WRKSRC}/README ${WRKSRC}/TODO \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
