# $NetBSD: Makefile,v 1.3 2020/03/20 11:57:38 nia Exp $

DISTNAME=	junicode-0-7-8
PKGNAME=	${DISTNAME:S/-7-8/.7.8/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=junicode/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://junicode.sourceforge.net/
COMMENT=	Free TrueType font family for medievalists
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/junicode
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/junicode
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF share/doc/junicode

do-install:
	cd ${WRKSRC}/fonts && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
