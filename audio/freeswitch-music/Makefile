# $NetBSD: Makefile,v 1.4 2023/12/28 23:35:19 zafer Exp $

DISTNAME=	freeswitch-music-1.0.8
CATEGORIES=	audio
MASTER_SITES=	https://files.freeswitch.org/releases/sounds/
DIST_SUBDIR=	freeswitch
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FreeSwitch Music - All Bitrates
LICENSE=	mpl-1.1

MUSICDIR=	share/freeswitch/sounds/music
PLIST_SUBST+=	MUSICDIR="${MUSICDIR}"
NO_BUILD=	yes

pre-install:
	${MV} ${WRKDIR}/music ${WRKDIR}/${DISTNAME}

do-install:
	@${ECHO_MSG} "Installing files..."
	for d in ${SOUND_DIRS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$d/* ${DESTDIR}${PREFIX}/${MUSICDIR}/$$d/; \
	done

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
