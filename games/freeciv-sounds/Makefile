# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:16 rillig Exp $

DISTNAME=	stdsounds3
PKGNAME=	freeciv-sounds-3.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/freeciv/contrib/sounds/sets/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Freeciv sound sets

DEPENDS+=	freeciv-share-[0-9]*:../../games/freeciv-share

WRKSRC=			${WRKDIR}/data
NO_BUILD=		yes

INSTALLATION_DIRS=	share/freeciv

do-install:
	${INSTALL_DATA} ${WRKSRC}/stdsounds.soundspec ${PREFIX}/share/freeciv/
	cd ${WRKSRC} && ${PAX} -rw stdsounds ${PREFIX}/share/freeciv/

.include "../../mk/bsd.pkg.mk"
