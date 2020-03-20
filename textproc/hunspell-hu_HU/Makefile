# $NetBSD: Makefile,v 1.7 2020/03/20 11:58:26 nia Exp $

VERSION=		1.6.1
DICTNAME=		hu_HU
PKGNAME=		hunspell-${DISTNAME}
DISTNAME=		${DICTNAME}-${VERSION}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=magyarispell/}

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		http://magyarispell.sourceforge.net/
COMMENT=		Hungarian dictionary for hunspell

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
	${INSTALL_DATA} ${WRKSRC}/README_${DICTNAME}.txt \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
