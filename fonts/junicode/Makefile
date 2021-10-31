# $NetBSD: Makefile,v 1.5 2021/10/31 14:11:20 rhialto Exp $

DISTNAME=	junicode-1.002
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=junicode/}
EXTRACT_SUFX=	.zip
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://junicode.sourceforge.io/
COMMENT=	Free TrueType font family for medievalists
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/junicode
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/junicode
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF share/doc/junicode

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
