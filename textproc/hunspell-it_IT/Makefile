# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:27 rillig Exp $

DISTNAME=	italiano_2_4_2007_09_01
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linguistico/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#		clamiax@gmail.com

HOMEPAGE=	https://linguistico.sourceforge.net/
COMMENT=	Italian dictionary for hunspell

DICTNAME=	it_IT
VERSION=	2.4
PKGNAME=	hunspell-${DICTNAME}-${VERSION}

NO_BUILD=		yes
PLIST_SUBST+=		DICTNAME=${DICTNAME}
WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_* \
		 ${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
