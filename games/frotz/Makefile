# $NetBSD: Makefile,v 1.34 2019/07/18 15:06:50 nia Exp $

DISTNAME=	frotz-2.44
CATEGORIES=	games
MASTER_SITES=	https://gitlab.com/DavidGriffith/frotz/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	https://davidgriffith.gitlab.io/frotz/
COMMENT=	Curses-based interpreter for Infocom-compatible games
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
MAKE_FLAGS+=	SOUND_DEFS=-DOSS_SOUND
MAKE_FLAGS+=	SOUND_LIB=${LIBOSSAUDIO}
CPPFLAGS+=	-DSOUND_DEV=\"${DEVOSSSOUND}\"
.endif

MAKE_FLAGS+=	CONFIG_DIR=${PKG_SYSCONFDIR}

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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
