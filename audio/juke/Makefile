# $NetBSD: Makefile,v 1.18 2017/01/04 16:50:31 roy Exp $
#

DISTNAME=	juke-0.7
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.moll.no/oyvind/distfiles/

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
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

INSTALLATION_DIRS=	${EGDIR} share/doc/juke

post-install:
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${DESTDIR}${EGDIR}/juke.conf.default
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${PREFIX}/share/doc/juke/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
