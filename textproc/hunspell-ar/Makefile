# $NetBSD: Makefile,v 1.4 2026/06/13 14:39:46 wiz Exp $

VERSION=		20080110
DICTNAME=		ar
PKGNAME=		${DISTNAME:S/_/-/}
DISTNAME=		hunspell-${DICTNAME}_${VERSION}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ayaspell/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=		Arabic dictionary for hunspell

USE_LANGUAGES=		# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}
PLIST_SUBST+=		DICTNAME=${DICTNAME}
MAKE_DIRS=		share/hunspell

do-build:	# nothing

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/README-en \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}/README_${DICTNAME}.txt

.include "../../mk/bsd.pkg.mk"
