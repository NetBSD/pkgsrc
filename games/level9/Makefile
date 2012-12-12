# $NetBSD: Makefile,v 1.16 2012/12/12 10:44:09 wiz Exp $

DISTNAME=		Level9_4.0_Source
PKGNAME=		level9-4.0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		Curses port of the Level 9 text adventure interpreter

WRKSRC=			${WRKDIR}/Unix
# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]*-* NetBSD-1.5*-* NetBSD-1.6-*
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6[A-L]*-*

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/level9 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/level9
	${INSTALL_DATA} ${WRKDIR}/level9.txt \
		${DESTDIR}${PREFIX}/share/doc/level9

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
