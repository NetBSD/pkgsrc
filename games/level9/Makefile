# $NetBSD: Makefile,v 1.2 2003/09/27 17:07:36 grant Exp $
#

DISTNAME=		Level9_3.0_Source
PKGNAME=		level9-3.0
WRKSRC=			${WRKDIR}/Unix
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		Curses port of the Level 9 text adventure interpreter

USE_BUILDLINK2=		yes
# uses halfkey (present since 1.6M), but still doesn't work
USE_NCURSES=		yes

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/level9
	${INSTALL_DATA} ${WRKDIR}/level9.txt ${PREFIX}/share/doc/level9
	${INSTALL_PROGRAM} ${WRKSRC}/level9 ${PREFIX}/bin

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
