# $NetBSD: Makefile,v 1.6 2023/12/28 23:37:07 zafer Exp $

DISTNAME=	freeswitch-sounds-fr-${VERSION}
VERSION=	1.0.18
CATEGORIES=	audio
MASTER_SITES=	https://files.freeswitch.org/releases/sounds/
DIST_SUBDIR=	freeswitch

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FreeSwitch Sounds (French)
LICENSE=	mpl-1.1

SOUNDSDIR=		share/freeswitch/sounds
USE_TOOLS+=		tar
INSTALLATION_DIRS+=	${SOUNDSDIR}
GENERATE_PLIST+=	\
	${FIND} ${WRKDIR}/fr \( -type f -o -type l \) -print \
	| ${SORT} | ${SED} -e "s,${WRKDIR}/,${SOUNDSDIR}/,g";
NO_BUILD=		yes

do-install:
	@${ECHO_MSG} "Installing files..."
	cd ${WRKDIR} && ${TAR} cf - fr | \
		${TAR} xf - -C ${DESTDIR}${PREFIX}/${SOUNDSDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
