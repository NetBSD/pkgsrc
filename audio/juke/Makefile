# $NetBSD: Makefile,v 1.21 2023/12/30 01:13:18 zafer Exp $
#

DISTNAME=	juke-0.7
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://www.moll.no/oyvind/distfiles/

MAINTAINER=	mob@bicekru.org
#HOMEPAGE=	http://johan.nocrew.org/nav10/unix/juke/
COMMENT=	Simple ncurses based jukebox
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
FAKE_NCURSES=	yes

EGDIR=		${PREFIX}/share/examples/juke

CONF_FILES=	${EGDIR}/juke.conf.default ${PKG_SYSCONFDIR}/juke.conf

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	doc/juke.1 MANUAL src/conf.c
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	PKG_SYSCONFDIR

INSTALLATION_DIRS=	${EGDIR} share/doc/juke

post-install:
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${DESTDIR}${EGDIR}/juke.conf.default
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${PREFIX}/share/doc/juke/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
