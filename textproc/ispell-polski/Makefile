# $NetBSD: Makefile,v 1.1.1.1 2003/09/30 13:43:16 adam Exp $
#

DISTNAME=	ispell-pl-20021127
PKGNAME=	${DISTNAME:S/-pl-/-polski-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ispell-pl/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://ispell-pl.sourceforge.net/
COMMENT=	Polish dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

do-build:
	cd ${WRKSRC} && ${SH} ./zbuduj.slownik.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/polish.aff ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/polish.hash ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
