# $NetBSD: Makefile,v 1.27 2012/10/06 11:54:39 asau Exp $

DISTNAME=	frotz-2.43
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=frotz/} \
		ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	http://frotz.sourceforge.net/
COMMENT=	Curses-based interpreter for Infocom-compatible games

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
MAKE_ENV+=	SOUND_DEFS=-DOSS_SOUND
MAKE_ENV+=	SOUND_LIB=${LIBOSSAUDIO}
MAKE_ENV+=	SOUND_DEV=${DEVOSSSOUND}
.endif

# setscrreg()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-V]-*

SAMPLEDIR=	${PREFIX}/share/examples/frotz
DOCDIR=		${PREFIX}/share/doc/frotz

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/frotz.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${SAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/frotz.conf-big \
		${DESTDIR}${SAMPLEDIR}/frotz.conf
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL HOW_TO_PLAY \
		${DESTDIR}${DOCDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
