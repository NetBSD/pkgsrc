# $NetBSD: Makefile,v 1.5 2020/03/20 11:58:27 nia Exp $
#

DISTNAME=	ispell-pl-20021127
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ispell-pl/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://ispell-pl.sourceforge.net/
COMMENT=	Polish dictionary for interactive spelling checker

CONFLICTS+=	ispell-polski-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

INSTALLATION_DIRS=	lib

do-build:
	cd ${WRKSRC} && ${SH} ./zbuduj.slownik.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/polish.aff ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/polish.hash ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
