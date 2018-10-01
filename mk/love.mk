# $NetBSD: love.mk,v 1.2 2018/10/01 18:25:17 maya Exp $
#
# Wrapper for LOVE2D games.
# Creates launchers for the required version.
#
# The following system variables must be defined before:
#	LOVE_GAME			Name of the executable created
#	LOVE_DATA			.love filename
#	LOVE_VERSION			LOVE version to be used. 0.8, 0.9, ..

do-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/${LOVE_GAME}
	${ECHO} '${PREFIX}/love${LOVE_VERSION}/bin/love ${PREFIX}/share/games/${LOVE_DATA}' \
		>> ${WRKSRC}/${LOVE_GAME}

LOVE_VERSION_NODOT=${LOVE_VERSION:S/.//}

INSTALLATION_DIRS+=	bin share/games
do-install:
	${INSTALL_DATA} ${WRKSRC}/${LOVE_DATA} ${DESTDIR}${PREFIX}/share/games/${LOVE_DATA}
	${INSTALL_SCRIPT} ${WRKSRC}/${LOVE_GAME} ${DESTDIR}${PREFIX}/bin/${LOVE_GAME}

DEPENDS+=	love${LOVE_VERSION_NODOT}-[0-9]*:../../games/love${LOVE_VERSION_NODOT}
