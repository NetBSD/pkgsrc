# $NetBSD: Makefile,v 1.1.1.1 2002/08/19 21:20:38 jwise Exp $
#

DISTNAME=	rom-spell
PKGNAME=	ispell-romanian-20020218
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.cmu.edu/~mihaib/ftp/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://fmg-www.cs.ucla.edu/fmg-members/geoff/ispell-dictionaries.html#Romanian-dicts
COMMENT=	Romanian dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

do-install:
	${INSTALL_DATA} ${WRKSRC}/rom.aff ${PREFIX}/lib/romanian.aff
	${INSTALL_DATA} ${WRKSRC}/rom.hash ${PREFIX}/lib/romanian.hash
	${INSTALL_DATA} ${WRKSRC}/rom.signs.aff ${PREFIX}/lib/romanian-signs.aff
	${INSTALL_DATA} ${WRKSRC}/rom.signs.hash ${PREFIX}/lib/romanian-signs.hash

.include "../../mk/bsd.pkg.mk"
