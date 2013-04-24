# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:46 rodent Exp $
#

DISTNAME=	rom-spell
PKGNAME=	ispell-ro-20031216
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.cmu.edu/~mihaib/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fmg-www.cs.ucla.edu/fmg-members/geoff/ispell-dictionaries.html#Romanian-dicts
COMMENT=	Romanian dictionary for ispell

CONFLICTS+=	ispell-romanian-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/rom.aff ${DESTDIR}${PREFIX}/lib/romanian.aff
	${INSTALL_DATA} ${WRKSRC}/rom.hash ${DESTDIR}${PREFIX}/lib/romanian.hash
	${INSTALL_DATA} ${WRKSRC}/rom.signs.aff ${DESTDIR}${PREFIX}/lib/romanian-signs.aff
	${INSTALL_DATA} ${WRKSRC}/rom.signs.hash ${DESTDIR}${PREFIX}/lib/romanian-signs.hash

.include "../../mk/bsd.pkg.mk"
