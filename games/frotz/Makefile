# $NetBSD: Makefile,v 1.45 2023/05/06 19:09:20 ryoon Exp $

DISTNAME=	frotz-2.54
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITLAB:=DavidGriffith/}
GITLAB_PROJECT=	frotz
GITLAB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	https://davidgriffith.gitlab.io/frotz/
COMMENT=	Curses-based interpreter for Infocom-compatible games
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=	curses
FAKE_NCURSES=	yes
USE_CURSES=	wide mouse

MAKE_FLAGS+=	CURSES=ncursesw
MAKE_FLAGS+=	CONFIG_DIR=${PKG_SYSCONFDIR}

.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} == "curses"
LDFLAGS+=	-lcurses
.else
MAKE_FLAGS+=	ITALIC=yes
.endif

SAMPLEDIR=	${PREFIX}/share/examples/frotz
DOCDIR=		${PREFIX}/share/doc/frotz

CONF_FILES+=	${SAMPLEDIR}/frotz.conf ${PKG_SYSCONFDIR}/frotz.conf

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

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
