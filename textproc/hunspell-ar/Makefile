# $NetBSD: Makefile,v 1.1.1.1 2009/10/12 20:52:40 ahoka Exp $

VERSION=		20080110
DICTNAME=		ar
PKGNAME=		${DISTNAME:S/_/-/}
DISTNAME=		hunspell-${DICTNAME}_${VERSION}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ayaspell/}

MAINTAINER=		pkgsrc-users@netbsd.org
HOMEPAGE=		http://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=		Arabic dictionary for hunspell

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
	${INSTALL_DATA} ${WRKSRC}/README-en \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}/README_${DICTNAME}.txt

.include "../../mk/bsd.pkg.mk"
