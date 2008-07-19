# $NetBSD: Makefile,v 1.1.1.1 2008/07/19 15:02:06 ahoka Exp $

VERSION=		2.3.2
DICTNAME=		fr_FR
PKGNAME=		hunspell-${DICTNAME}-${VERSION}
DISTNAME=		fr_FR_2-3-2
CATEGORIES=		textproc
MASTER_SITES=		http://dico.savant.free.fr/_download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dico.savant.free.fr/index.php
COMMENT=		French (Classic + 1990 Reform) dictionary for hunspell

EXTRACT_OPTS_ZIP=	-aqo # We don't want -L
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}
PLIST_SUBST+=		DICTNAME=${DICTNAME}
MAKE_DIRS=		share/hunspell
WRKSRC=			${WRKDIR}

do-build:	# nothing

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/README_${DICTNAME}.txt \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
