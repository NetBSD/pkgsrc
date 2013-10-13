# $NetBSD: Makefile,v 1.18 2013/10/13 10:19:22 wiz Exp $

DISTNAME=		Level9_5.1_Source
PKGNAME=		level9-5.1
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		Curses port of the Level 9 text adventure interpreter
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/Unix
# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]*-* NetBSD-1.5*-* NetBSD-1.6-*
INCOMPAT_CURSES+=	NetBSD-1.6.*-* NetBSD-1.6[A-L]*-*

INSTALLATION_DIRS=	bin share/doc/level9

LDADD+=			${BUILDLINK_LDADD.termcap}
LDADD+=			${BUILDLINK_LDADD.curses}
MAKE_ENV+=		LDADD=${LDADD:Q}

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/level9 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/level9.txt \
		${DESTDIR}${PREFIX}/share/doc/level9

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
