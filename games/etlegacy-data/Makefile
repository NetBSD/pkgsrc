# $NetBSD: Makefile,v 1.2 2019/07/26 11:32:07 wiz Exp $

DISTNAME=	et260b.x86_full
PKGNAME=	etlegacy-data-2.60b
CATEGORIES=	games
MASTER_SITES=	https://cdn.splashdamage.com/downloads/games/wet/
EXTRACT_SUFX=	.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.splashdamage.com/games/wolfenstein-enemy-territory/
COMMENT=	Wolfenstein: Enemy Territory data files for etlegacy
LICENSE=	et-eula-license

USE_TOOLS+=	tar pax
USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}

# zip contains script with binary data, -a cannot be used
EXTRACT_OPTS_ZIP=	-qo

INSTALLATION_DIRS+=	share/doc/etlegacy-data
INSTALLATION_DIRS+=	share/etlegacy/etmain

RESTRICTED=		Restrictions on charging a distribution fee.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

PAK3_FILES=		pak0.pk3 pak1.pk3 pak2.pk3

# this is never executed, the data is simply extracted from it.
CHECK_PORTABILITY_SKIP+=	et260b.x86_keygen_V03.run

do-build:
	cd ${WRKSRC} && ${TAIL} +402 ./et260b.x86_keygen_V03.run | ${TAR} xzf -

do-install:
.for file in ${PAK3_FILES}
	${INSTALL_DATA} ${WRKSRC}/etmain/${file} \
	    ${DESTDIR}${PREFIX}/share/etlegacy/etmain
.endfor
	cd ${WRKSRC}/Docs && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/doc/etlegacy-data

.include "../../mk/bsd.pkg.mk"
