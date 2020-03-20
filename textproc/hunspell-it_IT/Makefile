# $NetBSD: Makefile,v 1.5 2020/03/20 11:58:26 nia Exp $

DISTNAME=	italiano_2_4_2007_09_01
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linguistico/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#		clamiax@gmail.com

HOMEPAGE=	http://linguistico.sourceforge.net/
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
