# $NetBSD: Makefile,v 1.3 2012/10/03 11:24:38 asau Exp $
#

PKGNAME=    asterisk-sounds-native-20060209
DISTNAME=	asterisk-native-sounds-20060209-01-ulaw
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	asterisk-native-sounds-20060209-01-alaw.tar.bz2
CATEGORIES=	comms
MASTER_SITES=	http://mirror.astlinux.org/sounds/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.astlinux.org/index.php
COMMENT=	Asterisk sound files in higher quality formats

WRKSRC=		${WRKDIR}/sounds
USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	libdata/asterisk/sounds/dictate \
			libdata/asterisk/sounds/digits \
			libdata/asterisk/sounds/letters \
			libdata/asterisk/sounds/phonetic

# work around bogosity in distfile: tarred with non-x directories
post-extract:
	find ${WRKSRC} -type d -exec chmod a+x {} \;

do-install:
	cd ${WRKDIR} && \
		for f in `find sounds -type f -name \\*.?law` ; do \
			${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/libdata/asterisk/$$f; \
		done

.include "../../mk/bsd.pkg.mk"
