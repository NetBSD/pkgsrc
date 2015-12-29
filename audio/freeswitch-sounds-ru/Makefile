# $NetBSD: Makefile,v 1.3 2015/12/29 04:54:36 dholland Exp $

DISTNAME=	freeswitch-sounds-ru-${VERSION}
VERSION=	1.0.13
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
DIST_SUBDIR=	freeswitch

MAINTAINER=	darcy@NetBSD.org
COMMENT=	FreeSwitch Sounds (French)
LICENSE=	mpl-1.1

SOUNDSDIR=	share/freeswitch/sounds
USE_TOOLS+=	tar
INSTALLATION_DIRS+=	${SOUNDSDIR}
GENERATE_PLIST+= ${FIND} ${WRKDIR}/ru \( -type f -o -type l \) -print \
        | ${SORT} | ${SED} -e "s,${WRKDIR}/,${SOUNDSDIR}/,g";
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} "Installing files..."
	cd ${WRKDIR} && ${TAR} cf - ru | \
		${TAR} xf - -C ${DESTDIR}${PREFIX}/${SOUNDSDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
