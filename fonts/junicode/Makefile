# $NetBSD: Makefile,v 1.6 2021/11/05 18:56:54 rhialto Exp $

DISTNAME=	junicode-1.003
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=psb1558/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= Junicode-font

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://junicode.sourceforge.io/
COMMENT=	Free TrueType font family for medievalists
LICENSE=	ofl-v1.1

NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/junicode
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF share/doc/junicode

do-install:
	cd ${WRKSRC}/legacy && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
