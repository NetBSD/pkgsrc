# $NetBSD: Makefile,v 1.1.1.1 2009/10/12 21:14:51 ahoka Exp $

VERSION=		20090330		
DICTNAME=		sk_SK
PKGNAME=		hunspell-${DICTNAME}-${VERSION}
DISTNAME=		hunspell-sk-${VERSION}
CATEGORIES=		textproc
EXTRACT_SUFX=		.zip

MASTER_SITES=		http://www.sk-spell.sk.cx/files/

MAINTAINER=		pkgsrc-users@netbsd.org
HOMEPAGE=		http://www.sk-spell.sk.cx/hunspell-sk
COMMENT=		Slovak dictionary for hunspell

PKG_DESTDIR_SUPPORT=	user-destdir
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
	${INSTALL_DATA} ${WRKSRC}/doc/Copyright \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}/README_${DICTNAME}.txt

.include "../../mk/bsd.pkg.mk"
