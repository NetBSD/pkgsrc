# $NetBSD: Makefile,v 1.1.1.1 2008/07/19 14:46:43 ahoka Exp $

DICTNAME=		sv_SE
PKGNAME=		hunspell-${DISTNAME:S/sv/sv_SE/}
DISTNAME=		sv-1.27
CATEGORIES=		textproc
MASTER_SITES=		http://www.dsso.se/filer/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=		Swedish dictionary for hunspell

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
