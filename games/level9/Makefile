# $NetBSD: Makefile,v 1.8 2004/10/03 00:14:45 tv Exp $

DISTNAME=		Level9_3.0_Source
PKGNAME=		level9-3.0
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		Curses port of the Level 9 text adventure interpreter

WRKSRC=			${WRKDIR}/Unix
USE_BUILDLINK3=		yes
# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/level9
	${INSTALL_DATA} ${WRKDIR}/level9.txt ${PREFIX}/share/doc/level9
	${INSTALL_PROGRAM} ${WRKSRC}/level9 ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
