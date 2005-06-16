# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:54 jlam Exp $
#

DISTNAME=	stdsounds2
PKGNAME=	freeciv-sounds-2.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/freeciv/contrib/sounds/sets/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/sounds/
COMMENT=	Freeciv sound sets

DEPENDS=	freeciv-share-[0-9]*:../../games/freeciv-share

NO_BUILD=	YES

INSTALLATION_DIRS=	share/freeciv

do-install:
	${INSTALL_DATA} ${WRKDIR}/stdsounds.soundspec \
		${PREFIX}/share/freeciv/
	cd ${WRKDIR} && ${PAX} -rw stdsounds ${PREFIX}/share/freeciv/

.include "../../mk/bsd.pkg.mk"
